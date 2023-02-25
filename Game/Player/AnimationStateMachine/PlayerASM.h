#pragma once
#include "PlayerAnimationStates.h"
#include "../../../Engine/Enums.h"
#include "../../../Engine/AnimationStateMachine.h"

class PlayerUp;
class PlayerLeft;
class PlayerDown;
class PlayerRight;
class PlayerIdle;
class BaseState;

class PlayerASM : public AnimationStateMachine
{
public:
    PlayerASM(){}

    void start() override;
    void close();

    PlayerIdle* idleState = nullptr;
    PlayerLeft* leftState = nullptr;
    PlayerRight* rightState = nullptr;
    PlayerUp* upState = nullptr;
    PlayerDown* downState = nullptr;

    playerAnim stateEnum = IDLE;
};
