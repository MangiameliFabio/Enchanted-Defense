#pragma once

#define SINGLETON Singleton::getInstance()
#include <vector>

#include "Enums.h"
#include "Object.h"
#include "Texture.h"
#include "../Game/Player/PlayerCharacter.h"

class Singleton
{
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
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Textures to render
    std::vector<Texture*> gTextureContainer;

    //Delta Time
    float gDeltaTime = 1.f / 60.f;

    //Current Input State
    Inputs gCurrentInput = NONE;

    std::vector<Object*> updateFunctions;

    PlayerCharacter* Player;
};
