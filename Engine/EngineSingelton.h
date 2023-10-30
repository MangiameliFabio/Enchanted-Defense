#pragma once

#define ENGINE EngineSingleton::getInstance()
#define DELTA_TIME EngineSingleton::getInstance()->gDeltaTime
#define MEASURE_PERFORMANCE EngineSingleton::getInstance()->measurePerformance
#define DEBUG EngineSingleton::getInstance()->debug
#include "Core/Renderer.h"
#include "Core/Patterns/Subject.h"

class Object;
class Button;
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
    //Container witc1h contains objects for deletion
    std::vector<Object*> gQueueForDelete;

    std::vector<Button*> gButtons;

    //Delta Time
    float gDeltaTime = 1.f / 60.f;

    //Screen dimension constants
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;

    //Container sizes
    int gTotalObjects = 0;
    int gSizeQueueForDelete = 0;
    int gTotalButtons = 0;

    //Quit Game
    bool gQuit = false;

    //True for performance stats
    bool measurePerformance = false;
    //True to activate rendering of debugShapes
    bool debug = false;

    void addObject(Object* object)
    {
        gObjectList.push_back(object);
        gTotalObjects++;
    }

    void removeObject(const Object* object)
    {
        //Find Texture in vector
        const auto position = std::find(gObjectList.begin(), gObjectList.end(), object);

        //Remove Object
        if (position != gObjectList.end())
            gObjectList.erase(position);
        gTotalObjects--;
    }

    void addButton(Button* button)
    {
        gButtons.push_back(button);
        gTotalButtons++;
    }

    void removeButton(const Button* button)
    {
        //Find Texture in vector
        const auto position = std::find(gButtons.begin(), gButtons.end(), button);

        //Remove Object
        if (position != gButtons.end())
            gButtons.erase(position);
        gTotalButtons--;
    }

    void addToDeleteQueue(Object* object)
    {
        gQueueForDelete.push_back(object);
        gSizeQueueForDelete++;
    }
};
