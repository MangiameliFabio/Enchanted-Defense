#include "BaseEnemy.h"

#include "GameSingleton.h"

BaseEnemy::BaseEnemy() : BaseCharacter()
{
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::die()
{
    GAME->enemyCount--;
    mOnDeath();
}

void BaseEnemy::onDeath(std::function<void()> callback)
{
    mOnDeath = std::move(callback);
}
