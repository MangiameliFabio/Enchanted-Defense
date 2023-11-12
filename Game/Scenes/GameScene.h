#pragma once
#include <memory>
#include <vector>

#include "../../Engine/Core/Texture.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Scenes/BaseScene.h"

class BaseEnemy;
enum Event : int;
class EnemySpawner;

class GameScene : public BaseScene, Observer
{
    std::vector<std::shared_ptr<BaseEnemy>> enemyList;
    EnemySpawner* skeletonSpawner = nullptr;

    Texture background;

    Vector playerStart;
    Vector enemyStart;
    Vector spawnPoints[4];

    float waveCountDown = 2.f;

    int numEnemiesInLevel = 0;
    
public:
    GameScene();
    ~GameScene() override;
    void onNotify(const Event event) override;
    void startScene() override;
    void updateScene() override;
    void endScene() override;
    Vector& chooseRandomSpawn();
    float setRandomWaveCountDown(float min, float max);
    void addEnemyToList(const std::shared_ptr<BaseEnemy>& enemy);
    void removeEnemyFromList(const std::shared_ptr<BaseEnemy>& enemy);
};
