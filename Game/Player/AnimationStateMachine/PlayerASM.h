#pragma once

#include <memory>

#include "PlayerAnimationStates.h"
#include "../../../Engine/Enums.h"
#include "../../../Engine/Animation/AnimationStateMachine.h"
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
    PlayerASM() = default;
    ~PlayerASM() override;

    void init() override;
    void onNotify(const Event event) override;

    void update() override;

    std::shared_ptr<PlayerIdle> idleState = nullptr;
    std::shared_ptr<PlayerLeft> leftState = nullptr;
    std::shared_ptr<PlayerRight> rightState = nullptr;
    std::shared_ptr<PlayerUp> upState = nullptr;
    std::shared_ptr<PlayerDown> downState = nullptr;

    playerAnim stateEnum = IDLE;
};
