#include "MainMenu.h"

#include <memory>

#include "GameScene.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Debuging/Log.h"
#include "../../Engine/Scenes/SceneManager.h"

MainMenu::MainMenu()
{
    sceneMame = "MainMenu";
}

void MainMenu::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    titel = std::make_shared<TextBox>();
    titel->init("Enchanted Defense", &textColor, 48);
    titel->loadFromFile("assets/fonts/alagard.ttf");
    titel->setPosition(Vector((ENGINE->SCREEN_WIDTH - titel->getTexture()->getWidth()) / 2, 200));

    startButton = std::make_shared<Button>();
    startButton->init(&textColor);
    startButton->setButtonText("START", 48);
    startButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - startButton->getWidth()) / 2, 300));
    startButton->setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });
}

void MainMenu::updateScene()
{
    BaseScene::updateScene();
}

void MainMenu::endScene()
{
    BaseScene::endScene();
    
    background.free();
    titel->free();
    startButton->free();
}