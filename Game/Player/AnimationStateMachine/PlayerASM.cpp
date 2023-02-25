#include "PlayerASM.h"
#include "PlayerAnimationStates.h"

void PlayerASM::start()
{
    idleState = new PlayerIdle;
    leftState = new PlayerLeft;
    rightState = new PlayerRight;
    downState = new PlayerDown;
    upState = new PlayerUp;

    currentState = idleState;
    
    AnimationStateMachine::start();
}

void PlayerASM::close()
{
    AnimationStateMachine::close();

    idleState = nullptr;
    leftState = nullptr;
    rightState = nullptr;
    upState = nullptr;
    downState = nullptr;
}
