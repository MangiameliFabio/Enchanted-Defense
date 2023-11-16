#pragma once
#include <memory>

#include "BaseScene.h"

class SceneManager
{
    std::shared_ptr<BaseScene> currentScene = nullptr;

public:
    SceneManager();
    ~SceneManager();
    
    void update();
    
    template <class T>
    void changeScene()
    {
        //Only end scene if its valid
        if (currentScene)
        {
            currentScene->endScene();
        }
        currentScene = std::make_shared<T>();
        currentScene->startScene();
    }
};
