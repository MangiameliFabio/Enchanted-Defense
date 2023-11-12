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

void BaseEnemy::die()
{
    mOnDeath();
}

void BaseEnemy::onDeath(std::function<void()> callback)
{
    mOnDeath = std::move(callback);
}
