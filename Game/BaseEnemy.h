#pragma once
#include <functional>

#include "BaseCharacter.h"

class BaseEnemy : public BaseCharacter
{
public:
    BaseEnemy();
    ~BaseEnemy();

    virtual void onDeath() const;
    void setEventOnDeath(std::function<void()> callback);

private:
    std::function<void()> mOnDeath = nullptr;
};
