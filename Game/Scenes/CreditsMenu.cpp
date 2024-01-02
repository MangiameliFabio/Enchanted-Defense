#include "CreditsMenu.h"

#include "MainMenu.h"
#include "../../Engine/Scenes/SceneManager.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"

void CreditsMenu::startScene()
{
    BaseScene::startScene();
    
    background.loadTexture("assets/textures/MainMenuScreen.png");
    background.setStaticPosition({
        (ENGINE->SCREEN_WIDTH - background.getWidth()) / 2, (ENGINE->SCREEN_HEIGHT - background.getHeight()) / 2
    });

    constexpr SDL_Color textColor = {113, 0, 0, 0};

    title.init("Created by Fabio Mangiameli", textColor, 72);
    title.loadFromFile("assets/fonts/alagard.ttf");
    title.setPosition(Vector((ENGINE->SCREEN_WIDTH - title.getTexture()->getWidth()) / 2, 200));

    backButton.init(&textColor);
    backButton.setButtonText("MENU", 48);
    backButton.setPosition(Vector((ENGINE->SCREEN_WIDTH - backButton.getWidth()) / 2, 300));
    backButton.setCallback([] { GAME->sceneManager->changeScene<MainMenu>(); });

    //Load sprite sheet
    spriteSheet.loadTexture("assets/textures/enemies/skeleton.png");
    // spriteSheet.setDynamicPosition(&position);

    for(size_t i = 0; i < amountOfSkelis; i++)
    {
        //Create Animation
        auto skeli = std::make_shared<Animator>();
        skeli->addSpriteSheet(&spriteSheet, 4, 36, spriteSheet.getHeight());
        skeli->enable();
        skeli->setFrameRate(8.f);
    }
}

void CreditsMenu::endScene()
{
    BaseScene::endScene();
}
