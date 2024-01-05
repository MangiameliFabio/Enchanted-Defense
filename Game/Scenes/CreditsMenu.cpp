#include "CreditsMenu.h"

#include <memory>
#include <memory>

#include "MainMenu.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../GameSingleton.h"
#include "../Styles.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Animation/Animator.h"

#define PI 3.14159265

void CreditsMenu::startScene()
{
    BaseScene::startScene();

    background = std::make_shared<Texture>();
    background->loadTexture("assets/textures/MainMenuScreen.png");
    background->setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background->getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background->getHeight()) / 2
    });

    title = std::make_shared<StyledText>();
    title->init("Created by", TEXT_COLOR, TEXT_SIZE);
    title->loadFromFile("assets/fonts/alagard.ttf");
    title->setPosition(Vector((ENGINE->SCREEN_WIDTH - title->getTexture()->getWidth()) / 2, 150));
    title->createShadow(SHADOW_COLOR);

    secondTitle = std::make_shared<StyledText>();
    secondTitle->init("Fabio Mangiameli", TEXT_COLOR, HEADLINE_SIZE);
    secondTitle->loadFromFile("assets/fonts/alagard.ttf");
    secondTitle->setPosition(Vector((ENGINE->SCREEN_WIDTH - secondTitle->getTexture()->getWidth()) / 2, 200));
    secondTitle->createShadow(SHADOW_COLOR);

    backButton = std::make_shared<Button>();
    backButton->init(TEXT_COLOR);
    backButton->setButtonText("BACK", TEXT_SIZE);
    backButton->setPosition(Vector((ENGINE->SCREEN_WIDTH - backButton->getWidth()) / 2, 350));
    backButton->setCallback([] { GAME->gSceneManager->changeScene<MainMenu>(); });
    backButton->getButtonText()->createShadow(SHADOW_COLOR);

    for (int i = 0; i < amountOfSkelis; i++)
    {
        //Create Animation
        auto skeli = std::make_shared<Animator>();
        const double param = static_cast<double>(i) * 40 - 10;
        const float radius = 150;

        skeli->addSpriteSheet({0,0}, "assets/textures/enemies/skeleton.png", 4);
        skeli->enable();
        skeli->setFrameRate(8.f);
        skeli->getSpriteSheet()->setStaticPosition({
                                  static_cast<float>(cos(param * PI / 180.0)) * radius + (ENGINE->SCREEN_WIDTH - skeli->getWidth() - 16) / 2,
                                  static_cast<float>(sin(param * PI / 180.0)) * radius + 500,
                              });

        skeletons.push_back(skeli);
    }

    playerIdle = std::make_shared<Animator>();
    playerIdle->addSpriteSheet({
                                  0, 0
                              }, "assets/textures/Player/MoveDown.png", 5);
    playerIdle->enable();
    playerIdle->setFrameRate(8.f);
    playerIdle->getSpriteSheet()->setStaticPosition({(ENGINE->SCREEN_WIDTH - playerIdle->getWidth() - 16) / 2, 500});
}

void CreditsMenu::endScene()
{
    BaseScene::endScene();

    skeletons.clear();
    playerIdle = nullptr;
}

void CreditsMenu::updateScene()
{
    BaseScene::updateScene();

    for (auto skeli : skeletons)
    {
        skeli->update();
    }

    playerIdle->update();
}
