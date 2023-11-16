#include "PlayerAnimationStates.h"

#include "../../GameSingleton.h"
#include "../../../Engine/Animation/Animator.h"

PlayerIdle::PlayerIdle()
{
    idleSpriteSheet.loadTexture("assets/textures/player/Idle.png");
    idleSpriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(4.f);
    animation->addSpriteSheet(&idleSpriteSheet, 2, 56, idleSpriteSheet.getHeight());
}

void PlayerIdle::updateState()
{
    BaseState::updateState();

    switch (PLAYER->stateMachine->stateEnum)
    {
    case LEFT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->leftState.get());
        break;
    case RIGHT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->rightState.get());
        break;
    case UP:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->upState.get());
        break;
    case DOWN:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->downState.get());
        break;
    default
    : break;
    }
}

PlayerLeft::PlayerLeft()
{
    leftSpriteSheet.loadTexture("assets/textures/player/MoveRight_Left.png");
    leftSpriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&leftSpriteSheet, 2, 56, leftSpriteSheet.getHeight());

    animation->flip(SDL_FLIP_HORIZONTAL);
}

void PlayerLeft::updateState()
{
    BaseState::updateState();

    switch (PLAYER->stateMachine->stateEnum)
    {
    case IDLE:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->idleState.get());
        break;
    case RIGHT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->rightState.get());
        break;
    case UP:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->upState.get());
        break;
    case DOWN:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->downState.get());
        break;
    default
    : break;
    }
}

PlayerRight::PlayerRight()
{
    rightSpriteSheet.loadTexture("assets/textures/player/MoveRight_Left.png");
    rightSpriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&rightSpriteSheet, 2, 56, rightSpriteSheet.getHeight());
}

void PlayerRight::updateState()
{
    BaseState::updateState();

    switch (PLAYER->stateMachine->stateEnum)
    {
    case IDLE:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->idleState.get());
        break;
    case LEFT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->leftState.get());
        break;
    case UP:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->upState.get());
        break;
    case DOWN:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->downState.get());
        break;
    default
    : break;
    }
}

PlayerUp::PlayerUp()
{
    upSpriteSheet.loadTexture("assets/textures/player/MoveUp.png");
    upSpriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&upSpriteSheet, 2, 56, upSpriteSheet.getHeight());
}

void PlayerUp::updateState()
{
    BaseState::updateState();

    switch (PLAYER->stateMachine->stateEnum)
    {
    case IDLE:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->idleState.get());
        break;
    case LEFT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->leftState.get());
        break;
    case RIGHT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->rightState.get());
        break;
    case DOWN:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->downState.get());
        break;
    default
    : break;
    }
}

PlayerDown::PlayerDown()
{
    downSpriteSheet.loadTexture("assets/textures/player/MoveDown.png");
    downSpriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(16.f);
    animation->addSpriteSheet(&downSpriteSheet, 5, 56, downSpriteSheet.getHeight());
}

void PlayerDown::updateState()
{
    BaseState::updateState();

    switch (PLAYER->stateMachine->stateEnum)
    {
    case IDLE:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->idleState.get());
        break;
    case RIGHT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->rightState.get());
        break;
    case LEFT:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->leftState.get());
        break;
    case UP:
        PLAYER->stateMachine->stateTransition(PLAYER->stateMachine->upState.get());
        break;
    default
    : break;
    }
}
