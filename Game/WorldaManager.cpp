#include <random>

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

void WorldManager::init()
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
    PLAYER->addObserver(this);

    skeletonSpawner = new EnemySpawnerFor<SkeletonCharacter>();

    spawnPoints[0] = Vector(SINGLETON->SCREEN_WIDTH / 2, 70);
    spawnPoints[1] = Vector(70,SINGLETON->SCREEN_HEIGHT / 2);
    spawnPoints[2] = Vector(SINGLETON->SCREEN_WIDTH / 2, SINGLETON->SCREEN_HEIGHT - 70);
    spawnPoints[3] = Vector(SINGLETON->SCREEN_HEIGHT - 70,SINGLETON->SCREEN_WIDTH / 2);
}

void WorldManager::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        shouldUpdate = false;
    }
}

Vector& WorldManager::chooseRandomSpawn()
{
    std::random_device rd; // Get a random seed from the operating system
    std::mt19937 gen(rd()); // Use the Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> dis(0, 3);
    // Define a uniform distribution between 0 and sum of spawnPoints
    int randomNumber = dis(gen); // Generate a random integer between 0 and sum of spawnPoints

    return spawnPoints[randomNumber];
}

float WorldManager::setRandomWaveCountDown(float min, float max)
{
    std::random_device rd; // Get a random seed from the operating system
    std::mt19937 gen(rd()); // Use the Mersenne Twister 19937 generator
    std::uniform_real_distribution<float> dis(min, max); // Define a uniform distribution between min and max
    return dis(gen); // Generate a random float between min and max
}

void WorldManager::update()
{
    Object::update();

    if (SINGLETON->enemyCount >= 0)
    {
        if (waveCountDown <= 0)
        {
            waveCountDown = setRandomWaveCountDown(0.5f, 2.f);
            skeletonSpawner->spawnEnemy(chooseRandomSpawn());
        }
        else
        {
            waveCountDown -= DELTA_TIME;
        }
    }
    else
    {
        printf("YOU HAVE WON!");
    }
}
