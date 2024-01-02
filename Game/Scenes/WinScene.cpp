#include "WinScene.h"

#include "GameScene.h"
#include "MainMenu.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"

WinScene::WinScene()
{
    sceneMame = "GameScene";
}

WinScene::~WinScene()
{
}

void WinScene::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    title.init("YOU WIN!", textColor, 72);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 100));

    secondTitle.init("Thank you for playing", textColor, 48);
    secondTitle.loadFromFile("assets/fonts/alagard.ttf");
    secondTitle.setPosition(Vector((ENGINE->SCREEN_WIDTH - secondTitle.getTexture()->getWidth()) / 2, 200));
    
    restartButton.init(&textColor);
    restartButton.setButtonText("RESTART", 48);
    restartButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - restartButton.getWidth()) / 2, 300));
    restartButton.setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });

    menuButton.init(&textColor);
    menuButton.setButtonText("MENU", 48);
    menuButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - menuButton.getWidth()) / 2, 350));
    menuButton.setCallback([] { GAME->sceneManager->changeScene<MainMenu>(); });
}

void WinScene::endScene()
{
    BaseScene::endScene();
    
    background.free();
    title.free();
    secondTitle.free();
    restartButton.free();
    menuButton.free();
}
