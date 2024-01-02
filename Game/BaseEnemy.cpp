#include "BaseEnemy.h"

#include "GameSingleton.h"

BaseEnemy::BaseEnemy() : BaseCharacter()
{
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::onDeath() const
{
    mOnDeath();
}

void BaseEnemy::setEventOnDeath(std::function<void()> callback)
{
    mOnDeath = std::move(callback);
}
