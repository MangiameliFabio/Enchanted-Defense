#pragma once
#include <memory>
#include <vector>

#include "../../Engine/Core/Texture.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/TextBox.h"

class Soundtrack;
class BaseEnemy;
enum EEvent : int;
class EnemySpawner;

class GameScene : public BaseScene, Observer
{
    std::shared_ptr<EnemySpawner> skeletonSpawner = nullptr;

    std::shared_ptr<Texture> background = nullptr;
    std::shared_ptr<Texture> skeletonIcon = nullptr;

    std::shared_ptr<TextBox> textEnemyCount = nullptr;

    Vector playerStart;
    Vector enemyStart;
    Vector spawnPoints[12];

    float difficultyTimer = 5.f;
    float currentDifficultyTimer = difficultyTimer;

    float waveCountDown = 1.f;

    float minWaveCD = 0.5f;
    float maxWaveCD = 2.f;

public:
    GameScene();
    ~GameScene() override;
    void onNotify(const EEvent event) override;
    void startScene() override;
    void updateScene() override;
    void endScene() override;
    Vector& chooseRandomSpawn();
    float setRandomWaveCountDown(float min, float max);
};
