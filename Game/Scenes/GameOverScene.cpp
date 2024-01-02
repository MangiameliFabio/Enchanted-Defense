#include "GameOverScene.h"

#include "GameScene.h"
#include "MainMenu.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Scenes/SceneManager.h"

void GameOverScene::startScene()
{
    BaseScene::startScene();
    
    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    title.init("GAME OVER", textColor, 72);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 100));
    
    restartButton.init(&textColor);
    restartButton.setButtonText("RESTART", 48);
    restartButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - restartButton.getWidth()) / 2, 300));
    restartButton.setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });

    menuButton.init(&textColor);
    menuButton.setButtonText("MENU", 48);
    menuButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - menuButton.getWidth()) / 2, 350));
    menuButton.setCallback([] { GAME->sceneManager->changeScene<MainMenu>(); });
}

void GameOverScene::endScene()
{
    BaseScene::endScene();
    
    background.free();
    title.free();
    restartButton.free();
    menuButton.free();
}
