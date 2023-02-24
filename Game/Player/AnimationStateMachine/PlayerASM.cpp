#include "PlayerASM.h"
#include "PlayerAnimationStates.h"

PlayerASM::PlayerASM()
{
}

void PlayerASM::start()
{
    Object::start();

    idleState = new PlayerIdle;
    leftState = new PlayerLeft;
    rightState = new PlayerRight;
    downState = new PlayerDown;
    upState = new PlayerUp;

    currentState = idleState;
    if (!currentState)
    {
        printf("Current State is invalid");
    }
    else
    {
        currentState->startState();
    }
}

void PlayerASM::update()
{
    Object::update();

    currentState->updateState();
}

void PlayerASM::close()
{
    Object::close();
}

void PlayerASM::stateTransition(PlayerBaseState* state)
{
    currentState->endState();
    currentState = state;
    currentState->startState();
}
