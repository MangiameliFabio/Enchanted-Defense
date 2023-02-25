#include "ProjectileSpawner.h"

#include "Projectile.h"
#include "../Engine/Core/Vector.h"

void ProjectileSpawner::spawnProjectile(Vector& pos, Vector& dir)
{
    new Projectile(pos, dir);
}

void ProjectileSpawner::close()
{
    delete this;
}
