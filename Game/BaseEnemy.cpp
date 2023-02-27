#include "BaseEnemy.h"

#include "../Engine/Singelton.h"

BaseEnemy::BaseEnemy()
{
    SINGLETON->addEnemy(this);
}

BaseEnemy::~BaseEnemy()
{
    SINGLETON->enemyCount--;
    SINGLETON->removeEnemy(this);
}
