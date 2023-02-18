#include "Singelton.h"
#include "WorldMAnager.h"

WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
}

void WorldManager::createAssets()
{
    background.loadTexture("assets/textures/background.png");

    player.loadTexture("assets/textures/Player.png");
    player.x = (SINGLETON->SCREEN_WIDTH - player.getWidth()) / 2;
    player.y = (SINGLETON->SCREEN_HEIGHT - player.getHeight()) / 2;
}
