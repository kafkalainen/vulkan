#include "../headers/rt.hpp"
#include "../libkaf/glm/glm/vec4.hpp"
#include "../libkaf/glm/glm/mat4x4.hpp"

// int main(void)
// {
//     GLFWwindow *window;

//     std::cout << "hello world\n";
//     init_glfw();
//     create_glfw_window(&window);

//     uint32_t extensionCount = 0;
//     vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//     std::cout << extensionCount << " extensions supported\n";

//     while (!glfwWindowShouldClose(window))
//     {
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     glfwDestroyWindow(window);
// 	glfwTerminate();
// 	exit(EXIT_SUCCESS);
// }

int main(void)
{
    Application app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}