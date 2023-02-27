#include "PlayerASM.h"
#include "PlayerAnimationStates.h"
#include "../../../Engine/Singelton.h"

void PlayerASM::start()
{
    idleState = new PlayerIdle;
    leftState = new PlayerLeft;
    rightState = new PlayerRight;
    downState = new PlayerDown;
    upState = new PlayerUp;

    currentState = idleState;

    PLAYER->addObserver(this);

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

void PlayerASM::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}
