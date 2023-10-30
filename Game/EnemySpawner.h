#pragma once
#include "../Engine/Core/Object.h"

struct Vector;
class BaseEnemy;

class EnemySpawner
{
public:
    virtual ~EnemySpawner() = default;
    virtual BaseEnemy* spawnEnemy(Vector& spawnPoint) = 0;
};

template <class T>
class EnemySpawnerFor : public EnemySpawner
{
public:
    ~EnemySpawnerFor() override = default;
    BaseEnemy* spawnEnemy(Vector& spawnPoint) override { return new T(spawnPoint); }
};
