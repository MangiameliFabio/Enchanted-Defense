#pragma once
#include <string>

#include "../Debuging/Log.h"

class BaseScene
{
public:
    BaseScene() = default;
    virtual ~BaseScene() = default;

    virtual void startScene(){}
    virtual void updateScene(){}
    virtual void endScene(){}
};
