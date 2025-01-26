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
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow(APP_NAME, 640, 360, SDL_WINDOW_VULKAN);

    SDL_Log("Initialized with errors: %s", SDL_GetError());

    Uint32 count_instance_extensions;
    const char * const *instance_extensions = SDL_Vulkan_GetInstanceExtensions(&count_instance_extensions);

    
    //VulkanRenderer vulkanRenderer(window);
    //VkInstance vulkanInstance = vulkanRenderer.createInstance();

    //bool test = SDL_Vulkan_CreateSurface(window, vulkanInstance, nullptr, nullptr);

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