#include "vkrender.hpp"
#include <iostream>
#include <vulkan/vulkan.hpp>
#include <vector>
#include <fstream>

#include <iostream>

VulkanRenderer::VulkanRenderer(SDL_Window *window) : window(window) {}

VulkanRenderer::~VulkanRenderer()
{
}

VkInstance VulkanRenderer::createInstance()
{
    VkInstance instance;
    return instance;
}

std::vector<char> VulkanRenderer::readFile(const std::string& filePath){
    std::ifstream file(filePath, std::ios::ate | std::ios::binary);
    if(!file.is_open()){
        SDL_Log("Error openning file");
    }

    size_t fileSize = static_cast<size_t>(file.tellg());

    std::vector<char> buffer (fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();
    return buffer;
}

void VulkanRenderer::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath){
    auto fragCode = readFile(fragFilePath);
    auto vertCode = readFile(vertFilePath);

    std::cout << "Vertex code size: " << vertCode.size() << std::endl;
    std::cout << "Fragement code size: " << fragCode.size() << std::endl;

}

