#pragma once

#define ENGINE EngineSingleton::getInstance()
#define DELTA_TIME EngineSingleton::getInstance()->gDeltaTime
#define MEASURE_PERFORMANCE EngineSingleton::getInstance()->measurePerformance
#define DEBUG EngineSingleton::getInstance()->debug

#include "Core/Renderer.h"
#include "Core/Patterns/Subject.h"
#include "../Game/Player/PlayerCharacter.h"

class Pathfinding;
class BaseEnemy;

class EngineSingleton : public Subject
{
    static EngineSingleton* instance;

    EngineSingleton()
    {
        gRenderer = new Renderer;
    }

public:
    static EngineSingleton* getInstance()
    {
        if (!instance)
            instance = new EngineSingleton();

        return instance;
    }

    //The window renderer
    SDL_Renderer* gSDL_Renderer = nullptr;

    Renderer* gRenderer = nullptr;

    //Update functions
    std::vector<Object*> gObjectList;
    //Container with contains objects for deletion
    std::vector<Object*> gQueueForDelete;

    //Delta Time
    float gDeltaTime = 1.f / 60.f;

    //Screen dimension constants
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;

    //Container sizes
    int sizeObjectList = 0;
    int sizeQueueForDelete = 0;

    //Quit Game
    bool gQuit = false;

    //True for performance stats
    bool measurePerformance = false;
    //True to activate rendering of debugShapes
    bool debug = true;

    void addObject(Object* object)
    {
        gObjectList.push_back(object);
        sizeObjectList++;
    }

    void removeObject(Object* object)
    {
        //Find Texture in vector
        const auto position = std::find(gObjectList.begin(), gObjectList.end(), object);

        //Remove Object
        if (position != gObjectList.end())
            gObjectList.erase(position);
        sizeObjectList--;
    }

    void addToDeleteQueue(Object* object)
    {
        gQueueForDelete.push_back(object);
        sizeQueueForDelete++;
    }
};
