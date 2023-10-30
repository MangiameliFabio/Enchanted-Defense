#pragma once

#define GAME GameSingleton::getInstance()
#define PLAYER GameSingleton::getInstance()->gPlayer
#include <vector>

#include "Player/PlayerCharacter.h"

class BaseEnemy;
class Pathfinding;
class SceneManager;

class GameSingleton
{
    static GameSingleton* instance;

    GameSingleton(){}

public:
    static GameSingleton* getInstance()
    {
        if (!instance)
            instance = new GameSingleton();

        return instance;
    }


    //All enemies currently in the game
    std::vector<BaseEnemy*> gEnemiesList;

    //Player Reference
    PlayerCharacter* gPlayer = nullptr;

    //Pathfinding Grid
    Pathfinding* pathfindingGrid = nullptr;

    SceneManager* sceneManager = nullptr;

    int sizeEnemiesList = 0;

    //Enemies to kill for win
    int enemyCount = 50;

    void addEnemy(BaseEnemy* enemy)
    {
        gEnemiesList.push_back(enemy);
        sizeEnemiesList++;
    }

    void removeEnemy(BaseEnemy* enemy)
    {
        //Find Iterator of enemy
        const auto iterator = std::find(gEnemiesList.begin(), gEnemiesList.end(), enemy);

        //Remove Object
        if (iterator != gEnemiesList.end())
            gEnemiesList.erase(iterator);
        sizeEnemiesList--;
    }
};
