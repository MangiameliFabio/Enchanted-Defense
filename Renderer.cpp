#include "Renderer.h"

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Singelton.h"

bool Renderer::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                   SINGLETON->SCREEN_WIDTH,
                                   SINGLETON->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            SINGLETON->gRenderer =
                SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (SINGLETON->gRenderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(SINGLETON->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

void Renderer::renderUpdate()
{
    //Clear Screen
    SDL_SetRenderDrawColor(SINGLETON->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(SINGLETON->gRenderer);

    //Render all textures
    for (size_t i = 0; i < SINGLETON->gTextureContainer.size(); ++i)
    {
        SINGLETON->gTextureContainer[i]->render();
    }

    //Update screen
    SDL_RenderPresent(SINGLETON->gRenderer);
}

void Renderer::close()
{
    //Destroy window    
    SDL_DestroyRenderer(SINGLETON->gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SINGLETON->gRenderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}
