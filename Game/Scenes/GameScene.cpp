#include "GameScene.h"

#include <memory>
#include <random>

#include "GameOverScene.h"
#include "MainMenuScene.h"
#include "WinScene.h"
#include "../EnemySpawner.h"
#include "../SoundManager.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../Pathfinding.h"
#include "../Styles.h"
#include "../../Engine/Core/Soundtrack.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../Player/PlayerCharacter.h"
#include "../Skeleton/SkeletonCharacter.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::onNotify(const EEvent event)
{
    if (event == PLAYER_DIED)
    {
        GAME->gSceneManager->changeScene<GameOverScene>();
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
    textEnemyCount->init("x" + std::to_string(GAME->gKillCount), HUD_TEXT_COLOR, HUD_TEXT_SIZE);
    textEnemyCount->loadFromFile("assets/fonts/alagard.ttf");
    textEnemyCount->setPosition(75, 15);

    GAME->gSoundManager->getSoundtrack(IN_GAME_TRACK)->play(5000);

    GAME->gPathfindingGrid = std::make_shared<Pathfinding>(65, 65, 50, 50);
    GAME->gPathfindingGrid->init();
    GAME->gCurrentEnemyCount = GAME->gEnemyCount;
    GAME->gKillCount = GAME->gEnemyCount;

    const float playerStartPosX = ENGINE->SCREEN_WIDTH / 2;
    const float playerStartPosY = ENGINE->SCREEN_HEIGHT / 2;

    playerStart = Vector(playerStartPosX, playerStartPosY);
    PLAYER = std::make_shared<PlayerCharacter>();
    PLAYER->position = playerStart;
    PLAYER->init();
    PLAYER->addObserver(this);

    skeletonSpawner = std::make_shared<EnemySpawnerFor<SkeletonCharacter>>();

    //Spawn Points Top
    spawnPoints[0] = Vector(ENGINE->SCREEN_WIDTH / 2 - 50, 70);
    spawnPoints[1] = Vector(ENGINE->SCREEN_WIDTH / 2, 70);
    spawnPoints[2] = Vector(ENGINE->SCREEN_WIDTH / 2 + 50, 70);

    //Spawn Points Left
    spawnPoints[3] = Vector(70,ENGINE->SCREEN_HEIGHT / 2 - 50);
    spawnPoints[4] = Vector(70,ENGINE->SCREEN_HEIGHT / 2);
    spawnPoints[5] = Vector(70,ENGINE->SCREEN_HEIGHT / 2 + 50);

    //Spawn Points Bottom
    spawnPoints[6] = Vector(ENGINE->SCREEN_WIDTH / 2 - 50, ENGINE->SCREEN_HEIGHT - 70);
    spawnPoints[7] = Vector(ENGINE->SCREEN_WIDTH / 2, ENGINE->SCREEN_HEIGHT - 70);
    spawnPoints[8] = Vector(ENGINE->SCREEN_WIDTH / 2 + 50, ENGINE->SCREEN_HEIGHT - 70);

    //Spawn Points Right
    spawnPoints[9] = Vector(ENGINE->SCREEN_WIDTH - 70,ENGINE->SCREEN_HEIGHT / 2 - 50);
    spawnPoints[10] = Vector(ENGINE->SCREEN_WIDTH - 70,ENGINE->SCREEN_HEIGHT / 2);
    spawnPoints[11] = Vector(ENGINE->SCREEN_WIDTH - 70,ENGINE->SCREEN_HEIGHT / 2 + 50);
}

void GameScene::endScene()
{
    BaseScene::endScene();

    GAME->gSoundManager->getSoundtrack(IN_GAME_TRACK)->stop(500);

    GAME->gPathfindingGrid = nullptr;
    GAME->gSizeEnemiesList = 0;

    if (!GAME->gEnemyList.empty())
    {
        GAME->gEnemyList.clear();
    }

    if (GAME->gPlayer)
    {
        GAME->gPlayer = nullptr;
    }
}

Vector& GameScene::chooseRandomSpawn()
{
    std::random_device rd; // Get a random seed from the operating system
    std::mt19937 gen(rd()); // Use the Mersenne Twister 19937 generator
    std::uniform_int_distribution<int> dis(0, 11);
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

    textEnemyCount->setText("x" + std::to_string(GAME->gKillCount));

    if (GAME->gKillCount > 0)
    {
        if (GAME->gCurrentEnemyCount > 0)
        {
            if (currentDifficultyTimer <= 0)
            {
                minWaveCD *= 0.6f;
                maxWaveCD *= 0.6f;
                currentDifficultyTimer = difficultyTimer;
            }
            else
            {
                currentDifficultyTimer -= DELTA_TIME;
            }
            if (waveCountDown <= 0)
            {
                Vector spawnPoint = chooseRandomSpawn();
                bool spawnNewEnemy = true;

                if (GAME->gCurrentEnemyCount > 0)
                {
                    for (const auto& enemy : GAME->gEnemyList)
                    {
                        if (Vector::dist(enemy->position, spawnPoint) <= 50.f)
                        {
                            if (!enemy->collision->checkIfPointInCollision(spawnPoint))
                            {
                                spawnNewEnemy = false;
                            }
                        }
                    }
                }

                if (spawnNewEnemy)
                {
                    waveCountDown = setRandomWaveCountDown(minWaveCD, maxWaveCD);

                    std::shared_ptr<BaseEnemy> newEnemy = skeletonSpawner->spawnEnemy(spawnPoint);
                    GAME->addEnemy(newEnemy);

                    std::weak_ptr<BaseEnemy> enemyTemp(newEnemy);
                    newEnemy->setEventOnDeath([this, enemyTemp]
                    {
                        GAME->removeEnemy(enemyTemp);
                        GAME->gKillCount--;
                    });

                    GAME->gCurrentEnemyCount--;
                }
            }

            else
            {
                waveCountDown -= DELTA_TIME;
            }
        }
    }
    else
    {
        GAME->gSoundManager->getSoundEffect(WIN_SOUND)->play();
        GAME->gSceneManager->changeScene<WinScene>();
    }
}
