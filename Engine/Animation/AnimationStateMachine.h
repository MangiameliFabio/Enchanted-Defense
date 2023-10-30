﻿#pragma once

#include "../Core/Object.h"

class BaseState;
class AnimationStateMachine : public Object
{
protected:
    void update() override;

public:
    ~AnimationStateMachine() override;
    void init() override;
    virtual void stop();
    void stateTransition(BaseState* state);

    BaseState* currentState = nullptr;

    bool paused = false;
};
