#include "MainMenu.h"

#include <memory>

#include "CreditsMenu.h"
#include "GameScene.h"
#include "../GameSingleton.h"
#include "../Styles.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Scenes/SceneManager.h"

void MainMenu::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    title.init("Enchanted Defense", TEXT_COLOR, HEADLINE_SIZE);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 150));
    title.createShadow(SHADOW_COLOR);
    
    startButton.init(TEXT_COLOR);
    startButton.setButtonText("START", TEXT_SIZE);
    startButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - startButton.getWidth()) / 2, 300));
    startButton.setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });
    startButton.getButtonText()->createShadow(SHADOW_COLOR);
    
    creditsButton.init(TEXT_COLOR);
    creditsButton.setButtonText("CREDITS", TEXT_SIZE);
    creditsButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - creditsButton.getWidth()) / 2, 350));
    creditsButton.setCallback([] { GAME->sceneManager->changeScene<CreditsMenu>(); });
    creditsButton.getButtonText()->createShadow(SHADOW_COLOR);

    quitButton.init(TEXT_COLOR);
    quitButton.setButtonText("QUIT", TEXT_SIZE);
    quitButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - quitButton.getWidth()) / 2, 400));
    quitButton.setCallback([] { ENGINE->gQuit = true; });
    quitButton.getButtonText()->createShadow(SHADOW_COLOR);
}

void MainMenu::endScene()
{
    BaseScene::endScene();
}