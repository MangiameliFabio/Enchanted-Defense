#pragma once

#define SINGLETON Singleton::getInstance()
#include <vector>

#include "./Core/Object.h"
#include "./Core/Texture.h"
#include "../Game/Player/PlayerCharacter.h"
#include "Core/Renderer.h"
#include "Core/Patterns/Subject.h"

class Singleton : public Subject
{
    static Singleton* instance;

    Singleton()
    {
        gRenderer = new Renderer;
    }

public:
    static Singleton* getInstance()
    {
        if (!instance)
            instance = new Singleton();

        return instance;
    }

    //Player Refrence
    PlayerCharacter* gPlayer;

    //The window renderer
    SDL_Renderer* gSDL_Renderer = nullptr;

    Renderer* gRenderer = nullptr;

    //Update functions
    std::vector<Object*> gObjectList;

    //Delta Time
    float gDeltaTime = 1.f / 60.f;
    //Screen dimension constants
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;
    int numRenderTextures = 0;
    int numObjects = 0;

    bool gQuit = false;

    void addObject(Object* object)
    {
        gObjectList.push_back(object);
        numObjects++;
    }

    void removeObject(Object* object)
    {
        //Find Texture in vector
        const auto position = std::find(gObjectList.begin(), gObjectList.end(), object);

        //Remove Observer
        if (position != gObjectList.end())
            gObjectList.erase(position);
        numObjects--;
    }
};
