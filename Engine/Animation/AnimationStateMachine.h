#pragma once

class BaseState;
class AnimationStateMachine
{
public:
    virtual ~AnimationStateMachine();
    virtual void init();
    virtual void stop();
    void stateTransition(BaseState* state);
    virtual void update();

    BaseState* currentState = nullptr;

    bool paused = false;
};
