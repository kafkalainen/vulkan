#ifndef RT_HPP
#define RT_HPP
#define GLFW_INCLUDE_VULKAN
#include "../glfw/include/GLFW/glfw3.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>


class Application
{
    const uint32_t Width = 800;
    const uint32_t Height = 600;

    const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

    public:
        void run();

    private:
        GLFWwindow *m_window;
        VkInstance m_instance;
        
        void initGlfw();
        void initVulkan();
        void mainLoop();
        void cleanup();
};

int	init_glfw();
int	create_glfw_window(GLFWwindow **window);
void initialize_gl(GLuint *render_tex);

#endif