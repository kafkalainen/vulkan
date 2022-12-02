NAME = rt

SRCS = \
	main.cpp \
	glfw_utils.cpp \
	pipeline_initialize.cpp \
	glad.c \

HEADERS = \
	headers/rt.hpp \
	libkaf/libkaf.h \

CC = g++

ABS_DIR = $(shell pwd)
INCLUDES = -Ilibkaf -Iglad/include/ -Iglfw/GLFW/include
LIBS = -Llibkaf/
GLFW_SRCS = $(ABS_DIR)/glfw-3.3.4
GLFW_LIBS = $(ABS_DIR)/glfw
GLAD = $(ABS_DIR)/glad
CFLAGS_GLFW = $(shell export PKG_CONFIG_PATH=$(ABS_DIR)/glfw/lib/pkgconfig && pkg-config --cflags glfw3)
CFLAGS = -Wall -Wextra -Werror -g $(shell pkg-config --cflags gl) $(CFLAGS_GLFW) 
LIBS_GLFW = $(shell export PKG_CONFIG_PATH=$(ABS_DIR)/glfw/lib/pkgconfig && pkg-config --static --libs glfw3)
LDFLAGS = -lkaf $(LIBS_GLFW) "-Wl,-rpath,$(GLFW_LIBS)/lib"
SLASH = /
MKDIR := mkdir -p
RM = /bin/rm -rf
RESET = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"
OPENGL = $(shell pkg-config --libs gl)

S = srcs
O = objs
LIBKAF = libkaf$(SLASH)libkaf.a
SRC = $(addprefix $S$(SLASH), $(SRCS))
OBJ = $(SRC:$S%=$O%.o)

.PHONY: all clean fclean re

all: $(NAME)

test:
	@echo $(ABS_DIR)

dependencies:
	sudo apt install xorg-dev libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules libglu1-mesa-dev freeglut3-dev mesa-common-dev

$(GLFW_LIBS):
	@if [ ! -d $(GLFW_SRCS) ]; then \
		unzip glfw-3.3.4.zip; \
	fi
	@if [ ! -d $(GLFW_LIBS) ]; then \
		cmake -DCMAKE_INSTALL_PREFIX:PATH=$(GLFW_LIBS) -S $(GLFW_SRCS) -B $(GLFW_LIBS) && \
		cd $(GLFW_LIBS) && \
		make install; \
	fi

$(GLAD):
	@if [ ! -d $(GLAD) ]; then \
		mkdir -p glad && \
		unzip glad.zip -d glad && \
		mv glad/src/glad.c srcs/glad.c; \
	fi

$O:
	$(MKDIR) $@
	$(MKDIR) $@/utils

$(OBJ): | $O

$(OBJ): $O%.o: $S% $(HEADERS)
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDES) $<

$(LIBKAF):
	make -C libkaf

$(NAME): $(LIBKAF) $(GLFW_LIBS) $(GLAD) $(OBJ)
	$(CC) -o $@ $(INCLUDES) $(LIBS) $(CFLAGS) $(OBJ) $(LDFLAGS)
	@echo $(GREEN)Compiled executable $(NAME).

cleanobj:
ifneq ($(wildcard $(OBJ)),)
	@$(RM) $(wildcard $(OBJ))
endif

cleanobjdir: cleanobj
	@$(RM) $O

clean: cleanobjdir
	@if [ -d "$(GLFW_LIBS)" ] ; then \
	make -C $(GLFW_LIBS) clean ; \
	fi;
	@make -C libkaf clean
	@echo $(GREEN)Cleaned projects from object files.$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(GLFW_SRCS)
	@$(RM) $(GLFW_LIBS)
	@$(RM) $(GLAD)
	@make -C libkaf fclean
	@echo $(GREEN)Removed binaries and libraries.$(RESET)

re: fclean all