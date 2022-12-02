#ifndef RT_HPP
#define RT_HPP
#define WIDTH 800
#define HEIGHT 600

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"

int	init_glfw();
int	create_glfw_window(GLFWwindow **window);
void initialize_gl(GLuint *render_tex);

#endif