#include "AnimationStateMachine.h"
#include "BaseState.h"

#include <cstdio>

void AnimationStateMachine::start()
{
    Object::start();

    if (!currentState)
    {
        printf("Current State is invalid");
    }
    else
    {
        currentState->startState();
    }
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
