#include "SkeletonCharacter.h"

#include "../../Engine/Singelton.h"
#include "../../Engine/Pathfinding.h"
#include "../../Engine/Core/MeasurePerformance.h"

SkeletonCharacter::SkeletonCharacter(Vector& SpawnPosition)
{
    //Set spawn Position
    position = SpawnPosition;

    //Load sprite sheet
    spriteSheet.loadTexture("assets/textures/enemies/skeleton.png");
    spriteSheet.setDynamicPosition(&position);

    //Create Animation
    animation.addSpriteSheet(&spriteSheet, 4, 36, spriteSheet.getHeight());
    animation.enable();
    animation.setFrameRate(8.f);

    collision = new CollisionObject;
    collision->createCollisionShape(spriteSheet.getHeight(), spriteSheet.getWidth(), &position);

    name = typeid(this).name();
}

SkeletonCharacter::~SkeletonCharacter()
{
}

void SkeletonCharacter::update()
{
    auto timer = new MeasurePerformance;
    if (MEASURE_PERFORMANCE) { timer->start(); }
    BaseCharacter::update();
    if (MEASURE_PERFORMANCE) { timer->end("     Base Character Constructor: "); }


    if (MEASURE_PERFORMANCE) { timer->start(); }
    isMoving = true;
    if (pfCurrentCooldown <= 0)
    {
        pfCurrentCooldown = pfCooldown;
        if (!SINGLETON->pathfindingGrid->findPath(position, PLAYER->position, path, this))
        {
            isMoving = false;
        }
    }
    else
    {
        pfCurrentCooldown -= DELTA_TIME;
    }
    if (MEASURE_PERFORMANCE) { timer->end("     Pathfinding: "); }

    if (isMoving)
    {
        lastValidPos = position;
        move();
        if (checkForCollision())
        {
            position = lastValidPos;
        }
    }

    if (MEASURE_PERFORMANCE) { timer->start(); }
    animation.update();
    if (MEASURE_PERFORMANCE) { timer->end("     Animation: "); }
}

void SkeletonCharacter::move()
{
    if (!path.empty())
    {
        if (Vector::dist(path[0], position) <= 20.f)
        {
            path.erase(path.begin());
        }
        if (!path.empty())
        {
            Vector dir = (path[0] - position).normalize();
            position = position + dir * movementSpeed * DELTA_TIME;
        }
    }
}

void SkeletonCharacter::close()
{
    BaseEnemy::close();
}

bool SkeletonCharacter::checkForCollision()
{
    for (int enemy = 0; enemy < SINGLETON->sizeEnemiesList; ++enemy)
    {
        if (SINGLETON->gEnemiesList[enemy] != this)
        {
            if (Vector::dist(SINGLETON->gEnemiesList[enemy]->position, position) <= 100.f)
            {
                if (collision->checkForIntersection(SINGLETON->gEnemiesList[enemy]->collision))
                {
                    return true;
                }
            }
        }
        if (Vector::dist(PLAYER->position, position) <= 100.f)
            if (collision->checkForIntersection(PLAYER->collision))
            {
                close();
                return true;
            }
    }
    return false;
}
