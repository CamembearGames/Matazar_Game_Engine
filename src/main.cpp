#define VK_NO_PROTOTYPES

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "vkrender.hpp"

#define APP_NAME "Space Display"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow(APP_NAME, 640, 360, SDL_WINDOW_VULKAN);

    SDL_Log("Initialized with errors: %s", SDL_GetError());

    VulkanRenderer vulkanrenderer = VulkanRenderer(window);
    VkInstance vkinstance = vulkanrenderer.createInstance();
    vulkanrenderer.createGraphicsPipeline("shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv");


    bool running = true;
    while(running) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent))
            if(windowEvent.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }
    }

    SDL_DestroyWindow(window);
    SDL_Vulkan_UnloadLibrary();
    SDL_Quit();

    SDL_Log("Cleaned up with errors: %s", SDL_GetError());

    return 0;

}
