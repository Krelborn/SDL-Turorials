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

    cout << "Hooray it works!\n";
    SDL_Quit();

    return 0;
}
