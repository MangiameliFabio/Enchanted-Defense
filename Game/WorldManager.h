#pragma once

class EnemySpawner;

class WorldManager : public Object
{
public:
    WorldManager();
    ~WorldManager();

    void createAssets();

private:
    void update() override;

    EnemySpawner* skeletonSpawner;
    
    Texture background;
    Texture player;
    Texture arrow;

    Vector playerStart;
    Vector enemyStart;
};
