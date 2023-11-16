#pragma once
#include <functional>

#include "BaseCharacter.h"

class BaseEnemy : public BaseCharacter
{
public:
    BaseEnemy();
    ~BaseEnemy();
    virtual void die();
    virtual void clone();

    void onDeath(std::function<void()> callback);

private:
    std::function<void()> mOnDeath = nullptr;
};
