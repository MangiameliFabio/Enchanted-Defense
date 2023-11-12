#include "PlayerASM.h"

#include <memory>

#include "PlayerAnimationStates.h"
#include "../../GameSingleton.h"
#include "../PlayerCharacter.h"

void PlayerASM::init()
{
    idleState = std::make_shared<PlayerIdle>();
    leftState = std::make_shared<PlayerLeft>();
    rightState = std::make_shared<PlayerRight>();
    downState = std::make_shared<PlayerDown>();
    upState = std::make_shared<PlayerUp>();

    currentState = idleState;

    PLAYER->addObserver(this);

    AnimationStateMachine::init();
}

void PlayerASM::close()
{
    queuedForDelete = true;

    AnimationStateMachine::close();

    PLAYER->removeObserver(this);
}

void PlayerASM::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}
