#include "AnimationStateMachine.h"

#include "AnimationBaseState.h"
#include "../Debuging/Log.h"

void AnimationStateMachine::init()
{
    if (!currentState)
    {
        Log::print("Current State is invalid");
    }
    else
    {
        currentState->startState();
    }
}

void AnimationStateMachine::stop()
{
    currentState->animation->disable();
}

void AnimationStateMachine::update()
{
    currentState->updateState();
}

AnimationStateMachine::~AnimationStateMachine()
{
    currentState = nullptr;
}

void AnimationStateMachine::stateTransition(BaseState* state)
{
    currentState->endState();
    currentState = state;
    currentState->startState();
}
