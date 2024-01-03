#include "CreditsMenu.h"

#include "MainMenu.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Animation/Animator.h"

#define PI 3.14159265

void CreditsMenu::startScene()
{
    BaseScene::startScene();

    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    title.init("Created by", textColor, 48);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 150));

    secondTitle.init("Fabio Mangiameli", textColor, 72);
    secondTitle.loadFromFile("assets/fonts/alagard.ttf");
    secondTitle.setPosition(Vector((ENGINE->SCREEN_WIDTH - secondTitle.getTexture()->getWidth()) / 2, 200));

    backButton.init(&textColor);
    backButton.setButtonText("BACK", 48);
    backButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - backButton.getWidth()) / 2, 350));
    backButton.setCallback([] { GAME->sceneManager->changeScene<MainMenu>(); });

    for (int i = 0; i < amountOfSkelis; i++)
    {
        //Create Animation
        auto skeli = std::make_shared<Animator>();
        const double param = static_cast<double>(i) * 40 - 10;
        const float radius = 150;

        Log::print(static_cast<float>(cos(param * PI / 180.0)));
        Log::print(static_cast<float>(sin(param * PI / 180.0)));

        skeli->addSpriteSheet({0,0}, "assets/textures/enemies/skeleton.png", 4);
        skeli->enable();
        skeli->setFrameRate(8.f);
        skeli->getSpriteSheet()->setStaticPosition({
                                  static_cast<float>(cos(param * PI / 180.0)) * radius + (ENGINE->SCREEN_WIDTH - skeli->getWidth() - 16) / 2,
                                  static_cast<float>(sin(param * PI / 180.0)) * radius + 500,
                              });

        skeletons.push_back(skeli);
    }

    playerIdle.addSpriteSheet({
                                  0, 0
                              }, "assets/textures/Player/MoveDown.png", 5);
    playerIdle.enable();
    playerIdle.setFrameRate(8.f);
    playerIdle.getSpriteSheet()->setStaticPosition({(ENGINE->SCREEN_WIDTH - playerIdle.getWidth() - 16) / 2, 500});
}

void CreditsMenu::endScene()
{
    BaseScene::endScene();
}

void CreditsMenu::updateScene()
{
    BaseScene::updateScene();

    for (auto skeli : skeletons)
    {
        skeli->update();
    }

    playerIdle.update();
}
