#pragma once
#include "../Engine/Core/Object.h"

class EnemySpawner;

class GameManager : public Object
{
public:
    GameManager();
    ~GameManager() override;

    void init() override;

private:
    void update() override;
};
