#pragma once
#include <SDL_render.h>

#define SINGLETON Singleton::getInstance()

class Singleton
{
private:
    static Singleton* instance;
    Singleton() {}

public:
    static Singleton* getInstance()
    {
        if (!instance)
            instance = new Singleton();

        return instance;
    }

    //Modulation components
    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;
    
    //Modulation component
    Uint8 a = 255;

    //Angle of rotation
    double degrees = 0;

    //Flip type
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    
    //The window renderer
    SDL_Renderer* gRenderer = NULL;
};
