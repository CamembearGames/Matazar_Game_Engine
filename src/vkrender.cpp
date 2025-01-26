#include "vkrender.hpp"
#include <iostream>
#include <vulkan/vulkan.hpp>
#include <vector>

VulkanRenderer::VulkanRenderer(SDL_Window *window) : window(window) {}

VulkanRenderer::~VulkanRenderer()
{
    //cleanupVulkan();
}

VkInstance VulkanRenderer::createInstance()
{
    VkInstance instance;
    return instance;
}