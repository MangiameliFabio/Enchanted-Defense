#include "Renderer.h"

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "../Singelton.h"

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
            SINGLETON->gSDL_Renderer =
                SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (SINGLETON->gSDL_Renderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(SINGLETON->gSDL_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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
    SDL_SetRenderDrawColor(SINGLETON->gSDL_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(SINGLETON->gSDL_Renderer);

    //Render all textures
    for (size_t i = 0; i < textureContainer.size(); ++i)
    {
        if (textureContainer[i]->markForRender)
        {
            textureContainer[i]->render();
        }
    }

    //Update screen
    SDL_RenderPresent(SINGLETON->gSDL_Renderer);
}

void Renderer::addTexture(Texture* texture)
{
    textureContainer.push_back(texture);
    numTextures++;
}

void Renderer::removeTexture(Texture* texture)
{
    //Find Texture in vector
    const auto position = std::find(textureContainer.begin(), textureContainer.end(), texture);

    //Remove Observer
    if (position != textureContainer.end())
        textureContainer.erase(position);
    numTextures--;
}

void Renderer::close()
{
    //Destroy window    
    SDL_DestroyRenderer(SINGLETON->gSDL_Renderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SINGLETON->gSDL_Renderer = nullptr;

    IMG_Quit();
    SDL_Quit();

    delete this;
}
