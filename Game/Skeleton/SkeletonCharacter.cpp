#include "SkeletonCharacter.h"

#include <memory>

#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Core/MeasurePerformance.h"
#include "../../Engine/Core/CollisionObject.h"
#include "../../Engine/Debuging/DebugRectangle.h"
#include "../Pathfinding.h"
#include "../Player/PlayerCharacter.h"

SkeletonCharacter::SkeletonCharacter(Vector& SpawnPosition)
{
    //Set spawn Position
    position = SpawnPosition;

    //Load sprite sheet
    spriteSheet.loadTexture("assets/textures/enemies/skeleton.png");
    spriteSheet.setDynamicPosition(&position);

    //Create Animation
    animation = std::make_shared<Animator>();
    animation->addSpriteSheet(&spriteSheet, 4, 36, spriteSheet.getHeight());
    animation->enable();
    animation->setFrameRate(8.f);

    collision->createCollisionShape(spriteSheet.getHeight(), spriteSheet.getWidth(), &position);

    PLAYER->addObserver(this);
}

SkeletonCharacter::~SkeletonCharacter()
{
}

void SkeletonCharacter::update()
{
    lastValidPos = position;
    
    BaseCharacter::update();

    //Search new Path whenever cooldown is 0
    if (pfCurrentCooldown <= 0)
    {
        pfCurrentCooldown = pfCooldown;

        if (!GAME->pathfindingGrid->findPath(position, PLAYER->position, path, this))
        {
            printf("no path found in: %s \n", name.c_str());
        }
    }
    else
    {
        pfCurrentCooldown -= DELTA_TIME;
    }

    //Set direction to next path node
    if (setDirToPath())
    {
        velocity = moveDir * movementSpeed;
    }
    else
    {
        printf("failed to set move dir to path");
        velocity.Zero();
    }
    lastValidPos = position;
    move();
    if (checkForCollision())
    {
        move();
    }
    animation->update();
}

void SkeletonCharacter::move()
{
    position = position + velocity * DELTA_TIME;
}

void SkeletonCharacter::close()
{
    BaseEnemy::close();

    PLAYER->removeObserver(this);
}

bool SkeletonCharacter::checkForCollision()
{
    for (int enemy = 0; enemy < GAME->sizeEnemiesList; ++enemy)
    {
        if(GAME->gEnemyList.empty()){ return false;}
        if (GAME->gEnemyList[enemy].get() != this)
        {
            if (Vector::dist(GAME->gEnemyList[enemy]->position, position) <= 100.f)
            {
                if (collision->checkForIntersection(GAME->gEnemyList[enemy]->collision.get()))
                {
                    // if (collision->calculateCollisionPoint(SINGLETON->gEnemiesList[enemy]->collision, hit))
                    // {
                    //     moveDir += hit.normal;
                    //     return true;
                    // }
                    position = lastValidPos;
                    collision->collisionResponse(GAME->gEnemyList[enemy]->collision.get());
                    return true;
                }
            }
            if (Vector::dist(PLAYER->position, position) <= 100.f)
            {
                if (collision->checkForIntersection(GAME->gEnemyList[enemy]->collision.get()))
                {
                    // if (collision->calculateCollisionPoint(SINGLETON->gEnemiesList[enemy]->collision, hit))
                    // {
                    //     moveDir += hit.normal;
                    //     return true;
                    // }
                    PLAYER->die();
                    return true;
                }
            }
        }
    }
    return false;
}

bool SkeletonCharacter::setDirToPath()
{
    moveDir.Zero();

    if (!path.empty())
    {
        if (Vector::dist(path[0], position) <= 20.f)
        {
            path.erase(path.begin());
        }
        if (!path.empty())
        {
            moveDir += (path[0] - position).normalize();
            return true;
        }
    }
    return false;
}

void SkeletonCharacter::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        shouldUpdate = false;
    }
}
