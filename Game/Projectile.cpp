#include "Projectile.h"

#include "BaseEnemy.h"
#include "../Engine/Singelton.h"

void Projectile::update()
{
    Object::update();

    pos = pos + (velocity * DELTA_TIME);

    if (pos.x < 50.f || pos.y < 50.f || pos.x > SINGLETON->SCREEN_WIDTH - 50.f || pos.y > SINGLETON->SCREEN_WIDTH -
        50.f)
    {
        close();
        return;
    }
    for (auto enemy : SINGLETON->gEnemiesList)
    {
        if (Vector::dist(enemy->position, pos) <= 200.f)
        {
            if (projectileCollision->checkForIntersection(enemy->collision))
            {
                if (!enemy->queuedForDelete)
                {
                    enemy->close();
                    close();
                    break;
                }
            }
        }
    }
}

Projectile::Projectile(const Vector& pos_, const Vector& dir_)
{
    pos = pos_;
    dir = dir_;
    velocity = dir * projectileSpeed;

    texture.loadTexture("assets/textures/projectile.png");
    texture.setDynamicPosition(&pos);

    projectileCollision = new CollisionObject(this);
    projectileCollision->createCollisionShape(texture.getHeight(), texture.getWidth(), &pos);

    name = typeid(this).name();
}

void Projectile::close()
{
    Object::close();

    delete projectileCollision;
    projectileCollision = nullptr;
}
