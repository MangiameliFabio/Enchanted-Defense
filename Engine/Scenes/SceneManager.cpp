#include "SceneManager.h"
#include "BaseScene.h"

void SceneManager::update()
{
    currentScene->updateScene();
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
    currentScene = nullptr;
}
