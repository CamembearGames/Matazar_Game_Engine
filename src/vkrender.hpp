#pragma once

#include <vulkan/vulkan.hpp>
#include <SDL3/SDL.h>

class VulkanRenderer
{
public:
    VulkanRenderer(SDL_Window *window);
    ~VulkanRenderer();

    VkInstance createInstance();
    // VkPhysicalDevice selectPhysicalDevice(const VkInstance vulkanInstance);
    // VkDevice createDevice(const VkInstance vulkanInstance);

    void printInstanceInfoInConsole(const VkInstance vulkanInstance);

private:
    SDL_Window *window;
    VkInstance instance;
    VkDevice device;

    void cleanupVulkan();
};