#include "AnimationStateMachine.h"
#include "BaseState.h"

#include <cstdio>

void AnimationStateMachine::init()
{
    Object::init();
    name = typeid(this).name();

    if (!currentState)
    {
        printf("Current State is invalid");
    }
    else
    {
        currentState->startState();
    }
}

void AnimationStateMachine::stop()
{
    shouldUpdate = false;
    currentState->animation->disable();
}

void AnimationStateMachine::update()
{
    Object::update();

    currentState->updateState();
}

void AnimationStateMachine::stateTransition(BaseState* state)
{
    currentState->endState();
    currentState = state;
    currentState->startState();
}
