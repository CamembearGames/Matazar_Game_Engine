#pragma once

#include <vulkan/vulkan.hpp>
#include <SDL3/SDL.h>
#include <vector>
#include <string>

class VulkanRenderer
{
public:
    VulkanRenderer(SDL_Window *window);
    ~VulkanRenderer();

    VkInstance createInstance();
    void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

private:
    SDL_Window *window;
    VkInstance instance;
    VkDevice device;

    void cleanupVulkan();
    static std::vector<char> readFile(const std::string& filePath);
};
