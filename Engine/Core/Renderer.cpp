#include "Renderer.h"

#include <algorithm>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Debuging/DebugShape.h"
#include "../EngineSingelton.h"
#include "../Debuging/Log.h"
#include "../UI/TextBox.h"


bool Renderer::init()
{
    bool success = true;
    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               ENGINE->SCREEN_WIDTH,
                               ENGINE->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create vsynced renderer for window
        ENGINE->gSDL_Renderer =
            SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (ENGINE->gSDL_Renderer == nullptr)
        {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }
        }
    }


    return success;
}

void Renderer::renderUpdate()
{
    //Clear Screen
    SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(ENGINE->gSDL_Renderer);

    //Render all textures
    for (int i = 0; i < numTextures; ++i)
    {
        if (textureContainer[i]->markForRender)
        {
            textureContainer[i]->render();
        }
    }

    if (DEBUG)
    {
        //Render all textures
        for (int i = 0; i < numDebugShapes; ++i)
        {
            debugContainer[i]->render();
        }

        //Delete not persistent shapes
        for (auto debugShape : debugContainer)
        {
            if (!debugShape->persistent)
            {
                delete debugShape;
            }
        }
    }

    //Update screen
    SDL_RenderPresent(ENGINE->gSDL_Renderer);
}

void Renderer::addTexture(Texture* texture)
{
    textureContainer.push_back(texture);
    std::sort(textureContainer.begin(), textureContainer.end(), [](const Texture* a, const Texture* b)
    {
        return a->getZindex() < b->getZindex();
    });
    numTextures++;
}

void Renderer::addDebugShape(DebugShape* debugShape)
{
    debugContainer.push_back(debugShape);
    std::sort(debugContainer.begin(), debugContainer.end(), [](const DebugShape* a, const DebugShape* b)
    {
        return a->zIndex < b->zIndex;
    });

    numDebugShapes++;
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

void Renderer::removeDebugShape(DebugShape* debugShape)
{
    //Find Texture in vector
    const auto position = std::find(debugContainer.begin(), debugContainer.end(), debugShape);

    //Remove Observer
    if (position != debugContainer.end())
        debugContainer.erase(position);
    numDebugShapes--;
}

std::vector<Texture*>& Renderer::getTextures()
{
    return textureContainer;
}

void Renderer::close()
{
    //Destroy window    
    SDL_DestroyRenderer(ENGINE->gSDL_Renderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    ENGINE->gSDL_Renderer = nullptr;
}
