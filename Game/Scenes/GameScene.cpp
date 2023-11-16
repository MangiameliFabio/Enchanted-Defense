#include "GameScene.h"

#include <random>

#include "MainMenu.h"
#include "../EnemySpawner.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../Pathfinding.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../Player/PlayerCharacter.h"

#include "../Skeleton/SkeletonCharacter.h"

GameScene::GameScene()
{
    sceneMame = "GameScene";
}

GameScene::~GameScene()
{
}

void GameScene::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        GAME->sceneManager->changeScene<MainMenu>();
    }
}

void GameScene::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/environment/background.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    GAME->pathfindingGrid = std::make_shared<Pathfinding>(65, 65, 50, 50);
    GAME->pathfindingGrid->init();

    const float playerStartPosX = ENGINE->SCREEN_WIDTH / 2;
    const float playerStartPosY = ENGINE->SCREEN_HEIGHT / 2;

    playerStart = Vector(playerStartPosX, playerStartPosY);
    PLAYER = std::make_shared<PlayerCharacter>();
    PLAYER->position = playerStart;
    PLAYER->init();
    PLAYER->addObserver(this);

    skeletonSpawner = std::make_shared<EnemySpawnerFor<SkeletonCharacter>>();

    spawnPoints[0] = Vector(ENGINE->SCREEN_WIDTH / 2, 70);
    spawnPoints[1] = Vector(70,ENGINE->SCREEN_HEIGHT / 2);
    spawnPoints[2] = Vector(ENGINE->SCREEN_WIDTH / 2, ENGINE->SCREEN_HEIGHT - 70);
    spawnPoints[3] = Vector(ENGINE->SCREEN_HEIGHT - 70,ENGINE->SCREEN_WIDTH / 2);
}

void GameScene::endScene()
{
    BaseScene::endScene();
    
    background.free();

    if(!GAME->gEnemyList.empty())
    {
        GAME->gEnemyList.clear();
    }
    GAME->enemyCount = 0;

    if (GAME->gPlayer)
    {
        GAME->gPlayer->removeObserver(this);
        GAME->gPlayer = nullptr;
    }
}

Vector& GameScene::chooseRandomSpawn()
{
    std::random_device rd; // Get a random seed from the operating system
    std::mt19937 gen(rd()); // Use the Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> dis(0, 3);
    // Define a uniform distribution between 0 and sum of spawnPoints
    const int randomNumber = dis(gen); // Generate a random integer between 0 and sum of spawnPoints

    return spawnPoints[randomNumber];
}

float GameScene::setRandomWaveCountDown(float min, float max)
{
    std::random_device rd; // Get a random seed from the operating system
    std::mt19937 gen(rd()); // Use the Mersenne Twister 19937 generator
    std::uniform_real_distribution<float> dis(min, max); // Define a uniform distribution between min and max
    return dis(gen); // Generate a random float between min and max
}

void GameScene::updateScene()
{
    BaseScene::updateScene();

    if (GAME->enemyCount >= 0)
    {
        if (waveCountDown <= 0)
        {
            waveCountDown = setRandomWaveCountDown(0.5f, 2.f);
            std::shared_ptr<BaseEnemy> enemy = skeletonSpawner->spawnEnemy(chooseRandomSpawn());
            GAME->addEnemy(enemy);
            enemy->onDeath([this, enemy] { GAME->removeEnemy(enemy); });
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
