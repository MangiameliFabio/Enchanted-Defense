﻿#include "GameManager.h"
#include "GameSingleton.h"
#include "Scenes/GameScene.h"
#include "Scenes/MainMenu.h"

#include "../Engine/Core/Object.h"
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
    GAME->sceneManager = new SceneManager();
    GAME->sceneManager->addNewScene(new MainMenu);
    GAME->sceneManager->addNewScene(new GameScene);

    GAME->sceneManager->changeScene("MainMenu");
}

void GameManager::update()
{
    Object::update();

    GAME->sceneManager->update();
}
