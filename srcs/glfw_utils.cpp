#include "../headers/rt.hpp"
#include <iostream>


int	init_glfw()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return (EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return (EXIT_SUCCESS);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

int	create_glfw_window(GLFWwindow **window)
{
	*window = glfwCreateWindow(WIDTH, HEIGHT, "RT", NULL, NULL);
	if (*window == NULL)
	{
		std::cout << "Failed to open GLFW window." << std::endl;
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(*window);
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(0);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_FALSE);
	return (EXIT_SUCCESS);
}