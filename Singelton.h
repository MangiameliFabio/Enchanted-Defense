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
    
    //The window renderer
    SDL_Renderer* gRenderer = NULL;
};
