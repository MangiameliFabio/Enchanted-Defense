#pragma once
#include "BaseEnemy.h"
#include "../Engine/Core/Object.h"

struct Vector;
class BaseEnemy;

class EnemySpawner
{
public:
    virtual ~EnemySpawner() = default;
    virtual std::shared_ptr<BaseEnemy> spawnEnemy(Vector& spawnPoint) = 0;
};

template <class T>
class EnemySpawnerFor : public EnemySpawner
{
public:
    ~EnemySpawnerFor() override = default;
    std::shared_ptr<BaseEnemy> spawnEnemy(Vector& spawnPoint) override { return std::make_shared<BaseEnemy>(T(spawnPoint)); }
};
