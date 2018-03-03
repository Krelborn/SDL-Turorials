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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return -1;
    }

    while (true)
    {
        // Get the next event
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }

        // Randomly change the colour
        Uint8 red = rand() % 255;
        Uint8 green = rand() % 255;
        Uint8 blue = rand() % 255;

        // Fill the screen with the colour
        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    // Tidy up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
