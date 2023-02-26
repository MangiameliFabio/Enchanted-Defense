#pragma once
#include "../Engine/Core/Object.h"

struct Vector;
class BaseEnemy;

class EnemySpawner
{
public:
    ~EnemySpawner() {}
    virtual BaseEnemy* spawnEnemy(Vector& spawnPoint) = 0;
};

template <class T>
class EnemySpawnerFor : public EnemySpawner
{
public:
    virtual BaseEnemy* spawnEnemy(Vector& spawnPoint) { return new T(spawnPoint); }
};
