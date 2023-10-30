#include "PlayerASM.h"
#include "PlayerAnimationStates.h"
#include "../../GameSingleton.h"
#include "../PlayerCharacter.h"

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
    queuedForDelete = true;
    
    AnimationStateMachine::close();

    delete idleState;
    delete leftState;
    delete rightState;
    delete upState;
    delete downState;

    idleState = nullptr;
    leftState = nullptr;
    rightState = nullptr;
    upState = nullptr;
    downState = nullptr;

    PLAYER->removeObserver(this);
}

void PlayerASM::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}
