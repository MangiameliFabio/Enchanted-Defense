#include "GameScene.h"

#include <memory>
#include <random>

#include "GameOverScene.h"
#include "MainMenu.h"
#include "WinScene.h"
#include "../EnemySpawner.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../Pathfinding.h"
#include "../Styles.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../Player/PlayerCharacter.h"
#include "../Skeleton/SkeletonCharacter.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        GAME->sceneManager->changeScene<GameOverScene>();
    }
}

void GameScene::startScene()
{
    BaseScene::startScene();

    background = std::make_shared<Texture>();
    background->loadTexture("assets/textures/environment/background.png");
    background->setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background->getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background->getHeight()) / 2
    });

    skeletonIcon = std::make_shared<Texture>();
    skeletonIcon->loadTexture("assets/textures/enemies/SkeletonIcon.png");
    skeletonIcon->setStaticPosition({
        25, 15
    });

    textEnemyCount = std::make_shared<TextBox>();
    textEnemyCount->init("x" + std::to_string(GAME->enemyCount), HUD_TEXT_COLOR, HUD_TEXT_SIZE);
    textEnemyCount->loadFromFile("assets/fonts/alagard.ttf");
    textEnemyCount->setPosition(75, 15);

    GAME->pathfindingGrid = std::make_shared<Pathfinding>(65, 65, 50, 50);
    GAME->pathfindingGrid->init();
    GAME->currentEnemyCount = GAME->enemyCount;

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

    GAME->pathfindingGrid = nullptr;
    GAME->sizeEnemiesList = 0;
    GAME->currentEnemyCount = 0;

    if (!GAME->gEnemyList.empty())
    {
        GAME->gEnemyList.clear();
    }

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

    textEnemyCount->setText("x" + std::to_string(GAME->currentEnemyCount));

    if (GAME->currentEnemyCount > 0)
    {
        if (waveCountDown <= 0)
        {
            waveCountDown = setRandomWaveCountDown(0.5f, 2.f);
            std::shared_ptr<BaseEnemy> enemy = skeletonSpawner->spawnEnemy(chooseRandomSpawn());
            GAME->addEnemy(enemy);

            std::weak_ptr<BaseEnemy> enemyTemp(enemy);
            enemy->setEventOnDeath([this, enemyTemp]
            {
                GAME->removeEnemy(enemyTemp);
                GAME->currentEnemyCount--;
            });
        }
        else
        {
            waveCountDown -= DELTA_TIME;
        }
    }
    else
    {
        GAME->sceneManager->changeScene<WinScene>();
    }
}
