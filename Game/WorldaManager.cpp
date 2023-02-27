#include "EnemySpawner.h"
#include "Projectile.h"
#include "../Engine/Singelton.h"
#include "WorldMAnager.h"
#include "../Engine/Pathfinding.h"
#include "Player/PlayerCharacter.h"
#include "Skeleton/SkeletonCharacter.h"

WorldManager::WorldManager()
{
    name = typeid(this).name();
}

WorldManager::~WorldManager()
{
}

void WorldManager::createAssets()
{
    background.loadTexture("assets/textures/environment/background.png");
    background.staticX = (SINGLETON->SCREEN_WIDTH - background.getWidth()) / 2;
    background.staticY = (SINGLETON->SCREEN_HEIGHT - background.getHeight()) / 2;

    SINGLETON->pathfindingGrid = new Pathfinding(65, 65, 50, 50);

    const float playerStartPosX = SINGLETON->SCREEN_WIDTH / 2;
    const float playerStartPosY = SINGLETON->SCREEN_HEIGHT / 2;

    playerStart = Vector(playerStartPosX, playerStartPosY);
    auto player = new PlayerCharacter(playerStart);
    player->start();

    enemyStart = Vector(playerStartPosX, 50.f + 19.f);

    skeletonSpawner = new EnemySpawnerFor<SkeletonCharacter>();
    // skeletonSpawner->spawnEnemy(enemyStart);
}

void WorldManager::update()
{
    Object::update();

    static float cooldown = 0;
    static int ammount = 3;

    if (ammount > 0)
    {
        if (cooldown <= 0)
        {
            cooldown = 1.f;
            skeletonSpawner->spawnEnemy(enemyStart);
            ammount--;
        }
        else
        {
            cooldown -= DELTA_TIME;
        }
    }
}
