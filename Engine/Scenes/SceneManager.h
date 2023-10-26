#pragma once
#include <string>
#include <vector>

class BaseScene;

class SceneManager
{
    std::vector<BaseScene*> scenes;
    BaseScene* currentScene = nullptr;
    
    BaseScene* findSceneByName(const std::string& name) const;

public:
    void changeScene(std::string sceneName);
    void update();
    void addNewScene(BaseScene* newScene);
    
    SceneManager();
    ~SceneManager();
};
