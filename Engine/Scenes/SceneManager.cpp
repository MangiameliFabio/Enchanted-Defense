#include "SceneManager.h"
#include "BaseScene.h"

void SceneManager::update()
{
    currentScene->updateScene();
}

BaseScene* SceneManager::findSceneByName(const std::string& sceneName) const
{
    for (const auto scene : scenes)
    {
        if(scene->getSceneName() == sceneName)
        {
            return scene;
        }
    }

    return nullptr;
}

void SceneManager::changeScene(std::string sceneName)
{
    BaseScene* newScene = findSceneByName(sceneName);

    if(!newScene){
        printf("Couldn't switch scene because scene wasn't found");
        return;
    }

    //Only end scene if its valid
    if (currentScene)
    {
        currentScene->endScene();
    }
    currentScene = newScene;
    currentScene->startScene();
}

void SceneManager::addNewScene(BaseScene* newScene)
{
    scenes.push_back(newScene);
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
    scenes.clear();
    currentScene = nullptr;
}
