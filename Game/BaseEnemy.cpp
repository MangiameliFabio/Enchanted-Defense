#include "BaseEnemy.h"

#include "../Engine/Singelton.h"

BaseEnemy::BaseEnemy()
{
    SINGLETON->addEnemy(this);
}

BaseEnemy::~BaseEnemy()
{
    SINGLETON->removeEnemy(this);
}
