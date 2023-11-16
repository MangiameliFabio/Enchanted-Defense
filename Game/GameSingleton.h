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
    std::vector<std::shared_ptr<BaseEnemy>> gEnemyList;

    //Player Reference
    std::shared_ptr<PlayerCharacter> gPlayer = nullptr;

    //Pathfinding Grid
    std::shared_ptr<Pathfinding> pathfindingGrid = nullptr;

    std::shared_ptr<SceneManager> sceneManager = nullptr;

    int sizeEnemiesList = 0;

    //Enemies to kill for win
    int enemyCount = 50;

    void addEnemy(const std::shared_ptr<BaseEnemy>& enemy)
    {
        gEnemyList.push_back(enemy);
        sizeEnemiesList++;
    }

    void removeEnemy(const std::shared_ptr<BaseEnemy>& enemy)
    {
        //Find Iterator of enemy
        const auto iterator = std::find(gEnemyList.begin(), gEnemyList.end(), enemy);

        //Remove Object
        if (iterator != gEnemyList.end())
            gEnemyList.erase(iterator);
        sizeEnemiesList--;
    }
};
