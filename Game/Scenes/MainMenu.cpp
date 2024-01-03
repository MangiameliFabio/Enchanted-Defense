#include "MainMenu.h"

#include <memory>

#include "CreditsMenu.h"
#include "GameScene.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Scenes/SceneManager.h"

void MainMenu::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    title.init("Enchanted Defense", textColor, 72);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 150));
    title.createShadow({10, 0, 0, 140});
    
    startButton.init(&textColor);
    startButton.setButtonText("START", 48);
    startButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - startButton.getWidth()) / 2, 300));
    startButton.setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });
    startButton.getButtonText()->createShadow({10, 0, 0, 140});
    
    creditsButton.init(&textColor);
    creditsButton.setButtonText("CREDITS", 48);
    creditsButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - creditsButton.getWidth()) / 2, 350));
    creditsButton.setCallback([] { GAME->sceneManager->changeScene<CreditsMenu>(); });
    creditsButton.getButtonText()->createShadow({10, 0, 0, 140});

    quitButton.init(&textColor);
    quitButton.setButtonText("QUIT", 48);
    quitButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - quitButton.getWidth()) / 2, 400));
    quitButton.setCallback([] { ENGINE->gQuit = true; });
    quitButton.getButtonText()->createShadow({10, 0, 0, 140});
}

void MainMenu::endScene()
{
    BaseScene::endScene();
    
    background.free();
    title.free();
    startButton.free();
    creditsButton.free();
    quitButton.free();
}