#include "PlayerASM.h"

#include <memory>

#include "PlayerAnimationStates.h"
#include "../../GameSingleton.h"
#include "../PlayerCharacter.h"
#include "../../../Engine/EngineSingelton.h"

PlayerASM::~PlayerASM()
{
    ENGINE->removeObserver(this);

    idleState->free();
    leftState->free();
    rightState->free();
    downState->free();
    upState->free();
}

void PlayerASM::init()
{
    idleState = std::make_shared<PlayerIdle>();
    leftState = std::make_shared<PlayerLeft>();
    rightState = std::make_shared<PlayerRight>();
    downState = std::make_shared<PlayerDown>();
    upState = std::make_shared<PlayerUp>();

    currentState = idleState.get();

    PLAYER->addObserver(this);

    AnimationStateMachine::init();
}

void PlayerASM::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}

void PlayerASM::update()
{
    switch (stateEnum)
    {
    case LEFT:
        stateTransition(leftState.get());
        break;
    case RIGHT:
        stateTransition(rightState.get());
        break;
    case UP:
        stateTransition(upState.get());
        break;
    case DOWN:
        stateTransition(downState.get());
        break;
    case IDLE:
        stateTransition(idleState.get());
        break;
    }
}
