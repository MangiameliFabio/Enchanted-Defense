#pragma once
#include <memory>

#include "../Engine/Core/Object.h"
#include "../Engine/Core/Patterns/Observer.h"

class Soundtrack;
class EnemySpawner;

class GameManager : public Object
{
    std::shared_ptr<Soundtrack> menuMusic = nullptr;

public:
    std::shared_ptr<Soundtrack> getMenuMusic() const;
    std::shared_ptr<Soundtrack> getGameMusic() const;

private:
    std::shared_ptr<Soundtrack> gameMusic = nullptr;
    
public:
    GameManager();
    ~GameManager() override;

    void init() override;

private:
    void update() override;
};
