/*
#include "PlayerAnimationStates.h"

#include "../../GameSingleton.h"
#include "../../../Engine/Animation/Animator.h"

PlayerIdle::PlayerIdle()
{
    Texture spriteSheet;
    spriteSheet.loadTexture("assets/textures/player/Idle.png");
    spriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(4.f);
    animation->addSpriteSheet(&spriteSheet, 2, 56, getSpriteSheet()->getHeight());
}

void PlayerIdle::updateState()
{
    BaseState::updateState();

    
}

PlayerLeft::PlayerLeft()
{
    Texture spriteSheet;
    spriteSheet.loadTexture("assets/textures/player/MoveRight_Left.png");
    spriteSheet.setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&spriteSheet, 2, 56, spriteSheet.getHeight());

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
    getSpriteSheet()->loadTexture("assets/textures/player/MoveRight_Left.png");
    getSpriteSheet()->setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(getSpriteSheet(), 2, 56, getSpriteSheet()->getHeight());
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
    getSpriteSheet()->loadTexture("assets/textures/player/MoveUp.png");
    getSpriteSheet()->setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(getSpriteSheet(), 2, 56, getSpriteSheet()->getHeight());
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
    getSpriteSheet()->loadTexture("assets/textures/player/MoveDown.png");
    getSpriteSheet()->setDynamicPosition(&PLAYER->position);
    
    animation = std::make_shared<Animator>();
    animation->setFrameRate(16.f);
    animation->addSpriteSheet(getSpriteSheet(), 5, 56, getSpriteSheet()->getHeight());
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
*/
