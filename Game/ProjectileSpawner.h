#pragma once

struct Vector;

class ProjectileSpawner
{
public:
    void spawnProjectile(Vector& pos, Vector& dir);

    ProjectileSpawner(){}
    ~ProjectileSpawner(){}
};
