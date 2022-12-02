#include <iostream>
#include "../headers/rt.hpp"

int main(void)
{
    GLFWwindow *window;
    GLuint texture;

    std::cout << "hello world\n";
    init_glfw();
    create_glfw_window(&window);
    initialize_gl(&texture);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}