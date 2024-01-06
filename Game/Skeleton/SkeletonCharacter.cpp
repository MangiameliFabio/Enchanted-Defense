#include "SkeletonCharacter.h"

#include "../GameSingleton.h"
#include "../SoundManager.h"
#include "../Pathfinding.h"
#include "../Player/PlayerCharacter.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Core/MeasurePerformance.h"
#include "../../Engine/Core/CollisionObject.h"
#include "../../Engine/Core/SoundEffect.h"

SkeletonCharacter::SkeletonCharacter(const Vector& SpawnPosition)
{
    //Set spawn Position
    position = SpawnPosition;

    //Create Animation
    animation = std::make_shared<Animator>();
    animation->addSpriteSheet(&position, "assets/textures/enemies/skeleton.png", 4);
    animation->enable();
    animation->setFrameRate(8.f);

    collision->createCollisionShape(animation->getHeight(), animation->getWidth(), &position);

    PLAYER->addObserver(this);
}

SkeletonCharacter::~SkeletonCharacter()
{
    PLAYER->removeObserver(this);
}

void SkeletonCharacter::update()
{
    lastValidPos = position;
    
    BaseCharacter::update();

    //Search new Path whenever cooldown is 0
    if (pfCurrentCooldown <= 0)
    {
        pfCurrentCooldown = pfCooldown;

        if (!GAME->gPathfindingGrid->findPath(position, PLAYER->position, path, this))
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

    animation->update();
    
    checkForCollision();
}

void SkeletonCharacter::move()
{
    position = position + velocity * DELTA_TIME;
}

void SkeletonCharacter::close()
{
    BaseEnemy::close();
}

bool SkeletonCharacter::checkForCollision()
{
    for (int enemy = 0; enemy < GAME->gSizeEnemiesList; ++enemy)
    {
        if(GAME->gEnemyList.empty()){ return false;}
        if (GAME->gEnemyList[enemy].get() != this)
        {
            if (Vector::dist(PLAYER->position, position) <= 100.f)
            {
                if (collision->checkForIntersection(PLAYER->collision.get()))
                {
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

void SkeletonCharacter::onDeath() const
{
    GAME->gSoundManager->getSoundEffect(SKELETON_DEATH)->play();
    BaseEnemy::onDeath();
}

void SkeletonCharacter::onNotify(const EEvent event)
{
    if (event == PLAYER_DIED)
    {
        shouldUpdate = false;
    }
}
