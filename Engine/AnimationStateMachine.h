#pragma once
#include "Core/Object.h"

class BaseState;

class AnimationStateMachine : public Object
{
protected:
    void update() override;

public:
    void start() override;
    
    void stateTransition(BaseState* state);
    
    BaseState* currentState = nullptr;
};
