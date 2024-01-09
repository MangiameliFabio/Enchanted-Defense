#include "WinScene.h"

#include <memory>

#include "GameScene.h"
#include "MainMenuScene.h"
#include "../CustomButton.h"
#include "../SoundManager.h"
#include "../GameSingleton.h"
#include "../Styles.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Core/Soundtrack.h"
#include "../../Engine/UI/StyledText.h"

WinScene::WinScene()
{
}

WinScene::~WinScene()
{
}

void WinScene::startScene()
{
    BaseScene::startScene();

    background = std::make_shared<Texture>();
    background->loadTexture("assets/textures/MainMenuScreen.png");
    background->setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background->getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background->getHeight()) / 2
    });

    title = std::make_shared<StyledText>();
    title->init("YOU WIN!", TEXT_COLOR, HEADLINE_SIZE);
    title->loadFromFile("assets/fonts/alagard.ttf");
    title->setPosition(Vector((ENGINE->SCREEN_WIDTH - title->getTexture()->getWidth()) / 2, 100));
    title->createShadow(SHADOW_COLOR);

    secondTitle = std::make_shared<StyledText>();
    secondTitle->init("Thank you for playing", TEXT_COLOR, TEXT_SIZE);
    secondTitle->loadFromFile("assets/fonts/alagard.ttf");
    secondTitle->setPosition(Vector((ENGINE->SCREEN_WIDTH - secondTitle->getTexture()->getWidth()) / 2, 200));
    secondTitle->createShadow(SHADOW_COLOR);
    
    restartButton = std::make_shared<CustomButton>();
    restartButton->init(TEXT_COLOR);
    restartButton->setButtonText("RESTART", TEXT_SIZE);
    restartButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - restartButton->getWidth()) / 2, 300));
    restartButton->setCallback([] { GAME->gSceneManager->changeScene<GameScene>(); });
    restartButton->getButtonText()->createShadow(SHADOW_COLOR);

    menuButton = std::make_shared<CustomButton>();
    menuButton->init(TEXT_COLOR);
    menuButton->setButtonText("MENU", TEXT_SIZE);
    menuButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - menuButton->getWidth()) / 2, 350));
    menuButton->setCallback([]
    {
        GAME->gSoundManager->getSoundEffect(BUTTON_CLICK);
        GAME->gSceneManager->changeScene<MainMenuScene>();
    });
    menuButton->getButtonText()->createShadow(SHADOW_COLOR);

    GAME->gSoundManager->getSoundtrack(MENU_TRACK)->play(5000);
}

void WinScene::endScene()
{
    BaseScene::endScene();
}
