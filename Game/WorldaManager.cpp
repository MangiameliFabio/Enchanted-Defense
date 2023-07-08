﻿#include <random>

#include "EnemySpawner.h"
#include "GameSingleton.h"
#include "Projectile.h"
#include "..\Engine\EngineSingelton.h"
#include "WorldMAnager.h"
#include "Pathfinding.h"
#include "Player/PlayerCharacter.h"
#include "Skeleton/SkeletonCharacter.h"

GameSingleton* GameSingleton::instance = nullptr;

WorldManager::WorldManager()
{
    name = typeid(this).name();
}

WorldManager::~WorldManager()
{
}

void WorldManager::init()
{
    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.staticX = (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2;
    background.staticY = (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2;

    // startGame();
}

void WorldManager::startGame()
{
    background.loadTexture("assets/textures/environment/background.png");
    background.staticX = (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2;
    background.staticY = (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2;
    
    GAME->pathfindingGrid = new Pathfinding(65, 65, 50, 50);
    GAME->pathfindingGrid->init();
    
    const float playerStartPosX = ENGINE->SCREEN_WIDTH / 2;
    const float playerStartPosY = ENGINE->SCREEN_HEIGHT / 2;
    
    playerStart = Vector(playerStartPosX, playerStartPosY);
    auto player = new PlayerCharacter(playerStart);
    player->init();
    PLAYER->addObserver(this);
    
    skeletonSpawner = new EnemySpawnerFor<SkeletonCharacter>();
    
    spawnPoints[0] = Vector(ENGINE->SCREEN_WIDTH / 2, 70);
    spawnPoints[1] = Vector(70,ENGINE->SCREEN_HEIGHT / 2);
    spawnPoints[2] = Vector(ENGINE->SCREEN_WIDTH / 2, ENGINE->SCREEN_HEIGHT - 70);
    spawnPoints[3] = Vector(ENGINE->SCREEN_HEIGHT - 70,ENGINE->SCREEN_WIDTH / 2);
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

    // if (GAME->enemyCount >= 0)
    // {
    //     if (waveCountDown <= 0)
    //     {
    //         waveCountDown = setRandomWaveCountDown(0.5f, 2.f);
    //         skeletonSpawner->spawnEnemy(chooseRandomSpawn());
    //     }
    //     else
    //     {
    //         waveCountDown -= DELTA_TIME;
    //     }
    // }
    // else
    // {
    //     printf("YOU HAVE WON!");
    // }
}
