#pragma once
#include "../Engine/Core/Object.h"

class EnemySpawner;

class GameManager : public Object
{
public:
    GameManager();
    ~GameManager();

    void init();

private:
    void update() override;
};
