#pragma once

#define SINGLETON Singleton::getInstance()
#define PLAYER Singleton::getInstance()->gPlayer
#define DELTA_TIME Singleton::getInstance()->gDeltaTime
#define MEASURE_PERFORMANCE Singleton::getInstance()->measurePerformance
#define DEBUG Singleton::getInstance()->debug

#include "Core/Renderer.h"
#include "Core/Patterns/Subject.h"
#include "../Game/Player/PlayerCharacter.h"

class Pathfinding;
class BaseEnemy;

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

    //Pathfinding Grid
    Pathfinding* pathfindingGrid;

    //Update functions
    std::vector<Object*> gObjectList;
    //Container with contains objects for deletion
    std::vector<Object*> gQueueForDelete;
    //All enemies currently in the game
    std::vector<BaseEnemy*> gEnemiesList;

    //Delta Time
    float gDeltaTime = 1.f / 60.f;

    //Screen dimension constants
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;

    //Container sizes
    int sizeObjectList = 0;
    int sizeEnemiesList = 0;
    int sizeQueueForDelete = 0;

    bool gQuit = false;
    bool measurePerformance = false;
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

    void addEnemy(BaseEnemy* enemy)
    {
        gEnemiesList.push_back(enemy);
        sizeEnemiesList++;
    }

    void removeEnemy(BaseEnemy* enemy)
    {
        //Find Texture in vector
        const auto position = std::find(gEnemiesList.begin(), gEnemiesList.end(), enemy);

        //Remove Object
        if (position != gEnemiesList.end())
            gEnemiesList.erase(position);
        sizeEnemiesList--;
    }
};
