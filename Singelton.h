#pragma once

#define SINGLETON Singleton::getInstance()
#include <vector>

#include "Texture.h"

class Singleton
{
private:
    static Singleton* instance;

    Singleton()
    {
    }

public:
    static Singleton* getInstance()
    {
        if (!instance)
            instance = new Singleton();

        return instance;
    }

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 640;

    //Grid should start at x=100 and y=100

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Textures to render
    std::vector<Texture*> gTextureContainer;
};
