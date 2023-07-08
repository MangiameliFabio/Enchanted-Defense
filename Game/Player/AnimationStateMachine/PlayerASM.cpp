#include "PlayerASM.h"
#include "PlayerAnimationStates.h"
#include "..\..\GameSingleton.h"

void PlayerASM::init()
{
    idleState = new PlayerIdle;
    leftState = new PlayerLeft;
    rightState = new PlayerRight;
    downState = new PlayerDown;
    upState = new PlayerUp;

    currentState = idleState;

    PLAYER->addObserver(this);

    AnimationStateMachine::init();
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

void PlayerASM::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}
