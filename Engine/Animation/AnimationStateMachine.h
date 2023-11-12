#pragma once

#include <memory>

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
    void stateTransition(std::shared_ptr<BaseState> state);

    std::shared_ptr<BaseState> currentState = nullptr;

    bool paused = false;
};
