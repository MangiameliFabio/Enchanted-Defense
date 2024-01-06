#pragma once

#include <memory>

#include "PlayerAnimationStates.h"
#include "../../../Engine/Enums.h"
#include "../../../Engine/Animation/AnimationStateMachine.h"
#include "../../../Engine/Core/Patterns/Observer.h"

class BaseState;

class PlayerASM : public AnimationStateMachine, public Observer
{
public:
    PlayerASM() = default;
    ~PlayerASM() override;

    void init() override;
    void onNotify(const EEvent event) override;

    void update() override;

    std::shared_ptr<BaseState> idleState = nullptr;
    std::shared_ptr<BaseState> leftState = nullptr;
    std::shared_ptr<BaseState> rightState = nullptr;
    std::shared_ptr<BaseState> upState = nullptr;
    std::shared_ptr<BaseState> downState = nullptr;

    EPlayerAnim stateEnum = IDLE;
    EPlayerAnim lastStateEnum = stateEnum;
};
