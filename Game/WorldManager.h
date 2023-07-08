#pragma once

class EnemySpawner;

class WorldManager : public Object, public Observer
{
public:
    WorldManager();
    ~WorldManager();

    void init();
    void startGame();
    void onNotify(const Event event) override;
    Vector& chooseRandomSpawn();
    float setRandomWaveCountDown(float min, float max);

private:
    void update() override;

    EnemySpawner* skeletonSpawner;

    Texture background;
    Texture player;
    Texture arrow;

    Vector playerStart;
    Vector enemyStart;

    Vector spawnPoints[4];

    float waveCountDown = 2.f;
};
