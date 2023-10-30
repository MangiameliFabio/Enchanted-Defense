#include "BaseEnemy.h"

#include "GameSingleton.h"

BaseEnemy::BaseEnemy() : BaseCharacter()
{
    GAME->addEnemy(this);
}

BaseEnemy::~BaseEnemy()
{
    GAME->enemyCount--;
    GAME->removeEnemy(this);
}
