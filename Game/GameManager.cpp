#include "GameManager.h"

#include <memory>

#include "GameSingleton.h"
#include "SoundManager.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainMenuScene.h"

#include "../Engine/Core/Object.h"
#include "../Engine/Core/Soundtrack.h"
#include "../Engine/Scenes/SceneManager.h"

GameSingleton* GameSingleton::instance = nullptr;

GameManager::GameManager()
{
    name = typeid(this).name();
}

GameManager::~GameManager()
{
}

void GameManager::init()
{
    //Initialize sound manager and start menu sound track
    GAME->gSoundManager = std::make_shared<SoundManager>();
    GAME->gSoundManager->init();
    GAME->gSoundManager->getSoundtrack(MENU_TRACK)->play(1000);
    
    GAME->gSceneManager = std::make_shared<SceneManager>();
    GAME->gSceneManager->changeScene<MainMenuScene>();
}

void GameManager::update()
{
    Object::update();

    GAME->gSceneManager->update();
}
