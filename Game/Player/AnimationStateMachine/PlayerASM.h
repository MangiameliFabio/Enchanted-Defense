#pragma once
#include "PlayerAnimationStates.h"
#include "../../../Engine/Enums.h"
#include "../../../Engine/Core/Object.h"

class PlayerUp;
class PlayerLeft;
class PlayerDown;
class PlayerRight;
class PlayerIdle;
class PlayerBaseState;

class PlayerASM : public Object
{
    void update() override;

    PlayerBaseState* currentState = nullptr;

public:
    PlayerASM();

    void start() override;
    void close() override;

    void stateTransition(PlayerBaseState* state);

    PlayerIdle* idleState = nullptr;
    PlayerLeft* leftState = nullptr;
    PlayerRight* rightState = nullptr;
    PlayerUp* upState = nullptr;
    PlayerDown* downState = nullptr;

    playerAnim stateEnum = IDLE;
};
