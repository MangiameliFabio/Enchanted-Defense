#include "Projectile.h"

#include "BaseEnemy.h"
#include "GameSingleton.h"
#include "../Engine/EngineSingelton.h"

void Projectile::update()
{    
    Object::update();

    pos = pos + (velocity * DELTA_TIME);

    if (pos.x < 50.f || pos.y < 50.f || pos.x > ENGINE->SCREEN_WIDTH - 50.f || pos.y > ENGINE->SCREEN_WIDTH -
        50.f)
    {
        delete this;
        return;
    }
    for (const auto& enemy : GAME->gEnemyList)
    {
        if (Vector::dist(enemy->position, pos) <= 200.f)
        {
            if (projectileCollision->checkForIntersection(enemy->collision.get()))
            {
                if (!enemy->queuedForDelete)
                {
                    enemy->onDeath();
                    delete this;
                    break;
                }
            }
        }
    }
}

Projectile::Projectile(const Vector& pos_, const Vector& dir_) : Object()
{
    pos = pos_;
    dir = dir_;
    velocity = dir * projectileSpeed;

    texture.loadTexture("assets/textures/projectile.png");
    texture.setDynamicPosition(&pos);

    projectileCollision = std::make_shared<CollisionObject>();
    projectileCollision->createCollisionShape(texture.getHeight(), texture.getWidth(), &pos);

    name = typeid(this).name();
}

Projectile::~Projectile()
{
    texture.free();
}
