#pragma once
#include <string>

#include "../Debuging/Log.h"

class BaseScene
{
protected:
    std::string sceneMame;

public:
    std::string getSceneName() const;
    void setSceneName(const std::string& scene_mame);

    BaseScene() = default;
    virtual ~BaseScene() = default;

    virtual void startScene(){}
    virtual void updateScene(){}
    virtual void endScene(){}

};

inline std::string BaseScene::getSceneName() const
{
    return sceneMame;
}

inline void BaseScene::setSceneName(const std::string& scene_mame)
{
    sceneMame = scene_mame;
}
