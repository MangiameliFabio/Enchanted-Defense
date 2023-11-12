#include "AnimationStateMachine.h"
#include "AnimationBaseState.h"

#include <cstdio>

#include "../EngineSingelton.h"

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

AnimationStateMachine::~AnimationStateMachine()
{
    ENGINE->removeObject(this);
}

void AnimationStateMachine::stateTransition(std::shared_ptr<BaseState> state)
{
    currentState->endState();
    currentState = state;
    currentState->startState();
}
