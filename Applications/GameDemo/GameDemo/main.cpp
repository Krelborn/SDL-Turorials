//
//  main.cpp
//
//  Copyright © 2018 Compiled Creations Limited. All rights reserved.
//

#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#include <SDL2/SDL.h>

#pragma clang diagnostic pop

using std::cout;

int main(int argc, const char * argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Failed to initialise SDL\n";
        return -1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Demo Game",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640,
                                          480,
                                          SDL_WINDOW_OPENGL);
    if (window == nullptr)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    // Get an event
    SDL_Event event;
    SDL_PollEvent(&event);

    // Wait a bit
    SDL_Delay(3000);

    // Tidy up
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
