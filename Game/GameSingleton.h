#pragma once

#define GAME GameSingleton::getInstance()
#define PLAYER GameSingleton::getInstance()->gPlayer

#include "../Game/Player/PlayerCharacter.h"

class Pathfinding;
class BaseEnemy;

class GameSingleton : public Subject
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

    //Player Refrence
    PlayerCharacter* gPlayer;

    //Pathfinding Grid
    Pathfinding* pathfindingGrid;
    
    //All enemies currently in the game
    std::vector<BaseEnemy*> gEnemiesList;
    
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
        //Find Texture in vector
        const auto position = std::find(gEnemiesList.begin(), gEnemiesList.end(), enemy);

        //Remove Object
        if (position != gEnemiesList.end())
            gEnemiesList.erase(position);
        sizeEnemiesList--;
    }
};
