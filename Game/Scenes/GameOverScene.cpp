#include "GameOverScene.h"

#include "GameScene.h"
#include "MainMenu.h"
#include "../GameSingleton.h"
#include "../Styles.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../../Engine/UI/StyledText.h"

void GameOverScene::startScene()
{
    BaseScene::startScene();

    background = std::make_shared<Texture>();
    background->loadTexture("assets/textures/MainMenuScreen.png");
    background->setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background->getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background->getHeight()) / 2
    });
    
    title = std::make_shared<StyledText>();
    title->init("GAME OVER", TEXT_COLOR, HEADLINE_SIZE);
    title->loadFromFile("assets/fonts/alagard.ttf");
    title->setPosition(Vector((ENGINE->SCREEN_WIDTH - title->getTexture()->getWidth()) / 2, 100));
    title->createShadow(SHADOW_COLOR);

    restartButton = std::make_shared<Button>();
    restartButton->init(TEXT_COLOR);
    restartButton->setButtonText("RESTART", TEXT_SIZE);
    restartButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - restartButton->getWidth()) / 2, 300));
    restartButton->setCallback([] { GAME->sceneManager->changeScene<GameScene>(); });

    menuButton = std::make_shared<Button>();
    menuButton->init(TEXT_COLOR);
    menuButton->setButtonText("MENU", TEXT_SIZE);
    menuButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - menuButton->getWidth()) / 2, 350));
    menuButton->setCallback([] { GAME->sceneManager->changeScene<MainMenu>(); });
}

void GameOverScene::endScene()
{
    BaseScene::endScene();
}
