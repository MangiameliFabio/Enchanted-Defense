#pragma once

struct Vector;

class ProjectileSpawner
{
public:
    void spawnProjectile(Vector& pos, Vector& dir);

    void close();

    ProjectileSpawner(){}
    ~ProjectileSpawner(){}
};
