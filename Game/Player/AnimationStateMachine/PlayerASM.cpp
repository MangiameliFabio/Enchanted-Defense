#include "PlayerASM.h"

#include <memory>

#include "PlayerAnimationStates.h"
#include "../../GameSingleton.h"
#include "../PlayerCharacter.h"
#include "../../../Engine/EngineSingelton.h"
#include "../../../Engine/Animation/AnimationBaseState.h"
#include "../../../Engine/Debuging/Log.h"

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
    idleState = std::make_shared<BaseState>(&PLAYER->position, "assets/textures/player/Idle.png", 4.f, 2);
    leftState = std::make_shared<BaseState>(&PLAYER->position, "assets/textures/player/MoveRight_Left.png", 8.f, 2, 
                                            SDL_FLIP_HORIZONTAL);
    rightState = std::make_shared<BaseState>(&PLAYER->position, "assets/textures/player/MoveRight_Left.png", 8.f, 2);
    downState = std::make_shared<BaseState>(&PLAYER->position, "assets/textures/player/MoveDown.png", 16.f, 5);
    upState = std::make_shared<BaseState>(&PLAYER->position, "assets/textures/player/MoveUp.png", 8.f, 2);

    currentState = idleState.get();

    PLAYER->addObserver(this);

    AnimationStateMachine::init();
}

void PlayerASM::onNotify(const EEvent event)
{
    if (event == PLAYER_DIED)
    {
        stop();
    }
}

void PlayerASM::update()
{
    AnimationStateMachine::update();
    
    if(stateEnum != lastStateEnum)
    {
        switch (stateEnum)
        {
        case LEFT:
            lastStateEnum = stateEnum;
            stateTransition(leftState.get());
            break;
        case RIGHT:
            lastStateEnum = stateEnum;
            stateTransition(rightState.get());
            break;
        case UP:
            lastStateEnum = stateEnum;
            stateTransition(upState.get());
            break;
        case DOWN:
            lastStateEnum = stateEnum;
            stateTransition(downState.get());
            break;
        case IDLE:
            lastStateEnum = stateEnum;
            stateTransition(idleState.get());
            break;
        }
    }
}
