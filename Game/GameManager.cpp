#include "GameManager.h"

#include <memory>

#include "GameSingleton.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainMenu.h"

#include "../Engine/Core/Object.h"
#include "../Engine/Core/Soundtrack.h"
#include "../Engine/Scenes/SceneManager.h"

GameSingleton* GameSingleton::instance = nullptr;

std::shared_ptr<Soundtrack> GameManager::getMenuMusic() const
{
    return menuMusic;
}

std::shared_ptr<Soundtrack> GameManager::getGameMusic() const
{
    return gameMusic;
}

GameManager::GameManager()
{
    name = typeid(this).name();
}

GameManager::~GameManager()
{
    menuMusic->close();
    gameMusic->close();
}

void GameManager::init()
{
    GAME->gSceneManager = std::make_shared<SceneManager>();
    GAME->gSceneManager->changeScene<MainMenu>();
    
    menuMusic = std::make_shared<Soundtrack>();
    menuMusic->init("assets/sounds/music/menu_music.mp3");
    menuMusic->play(1000);

    GAME->gSceneState = MENU;

    gameMusic = std::make_shared<Soundtrack>();
    gameMusic->init("assets/sounds/music/game_music.mp3");
}

void GameManager::update()
{
    Object::update();

    GAME->gSceneManager->update();
}
