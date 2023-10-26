#pragma once
#include "../../Engine/Core/Texture.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Scenes/BaseScene.h"

enum Event : int;
class EnemySpawner;

class GameScene : public BaseScene, Observer
{
    EnemySpawner* skeletonSpawner = nullptr;

    Texture background;

    Vector playerStart;
    Vector enemyStart;
    Vector spawnPoints[4];

    float waveCountDown = 2.f;
    
public:
    GameScene();
    ~GameScene() override;
    void onNotify(const Event event) override;
    void startScene() override;
    void updateScene() override;
    void endScene() override;
    Vector& chooseRandomSpawn();
    float setRandomWaveCountDown(float min, float max);
};
