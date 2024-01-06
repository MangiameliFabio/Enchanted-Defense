#pragma once
#include <memory>

#include "../Engine/Core/Object.h"
#include "../Engine/Core/Patterns/Observer.h"

class Soundtrack;
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
