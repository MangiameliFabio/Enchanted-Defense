#include "MainMenu.h"

#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Debuging/Log.h"
#include "../../Engine/Scenes/SceneManager.h"

MainMenu::MainMenu()
{
    sceneMame = "MainMenu";
}

MainMenu::~MainMenu()
{
    MainMenu::endScene();
}

void MainMenu::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.staticX = (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2;
    background.staticY = (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2;

    const SDL_Color textColor = {113, 0, 0};
    titel.init("Enchanted Defense", &textColor, 48);
    titel.loadFromFile("assets/fonts/alagard.ttf");
    titel.setPosition(Vector(ENGINE->SCREEN_WIDTH / 2 - titel.getTexture()->getWidth() / 2, 200));
}

void MainMenu::updateScene()
{
    BaseScene::updateScene();

    static float count = 5.f;

    if (count <= 0.f)
    {
        count = 5.f;
        GAME->sceneManager->changeScene("GameScene");
    }

    count -= DELTA_TIME;
}

void MainMenu::endScene()
{
    BaseScene::endScene();

    background.free();
    titel.free();
}
