#pragma once
#include "PlayerAnimationStates.h"
#include "../../../Engine/Enums.h"
#include "../../../Engine/AnimationStateMachine.h"
#include "../../../Engine/Core/Patterns/Observer.h"

class PlayerUp;
class PlayerLeft;
class PlayerDown;
class PlayerRight;
class PlayerIdle;
class BaseState;

class PlayerASM : public AnimationStateMachine, public Observer
{
public:
    PlayerASM(){}

    void init() override;
    void close() override;
    void onNotify(const Event event) override;
    
    PlayerIdle* idleState = nullptr;
    PlayerLeft* leftState = nullptr;
    PlayerRight* rightState = nullptr;
    PlayerUp* upState = nullptr;
    PlayerDown* downState = nullptr;

    playerAnim stateEnum = IDLE;
};
