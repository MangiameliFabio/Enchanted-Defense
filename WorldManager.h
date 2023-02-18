#pragma once
#include "Texture.h"

class WorldManager
{
public:
    WorldManager();
    ~WorldManager();

    void createAssets();

private:
    Texture background;
    Texture player;
    Texture arrow;
};
