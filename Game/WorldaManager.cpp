#include "../Engine/Singelton.h"
#include "WorldMAnager.h"
#include "Player/PlayerCharacter.h"

WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
}

void WorldManager::createAssets()
{
    background.loadTexture("assets/textures/environment/background.png");
    background.staticX = (SINGLETON->SCREEN_WIDTH - background.getWidth()) / 2;
    background.staticY = (SINGLETON->SCREEN_HEIGHT - background.getHeight()) / 2;

    const float playerStartPosX = SINGLETON->SCREEN_HEIGHT / 2;
    const float playerStartPosY = SINGLETON->SCREEN_HEIGHT / 2;

    Vector spawnPos = Vector(playerStartPosX, playerStartPosY);
    auto player = new PlayerCharacter(spawnPos);
    player->start();
}
