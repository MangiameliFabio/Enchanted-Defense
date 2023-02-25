#include "PlayerAnimationStates.h"
#include "../../../Engine/Singelton.h"
#include "../../../Engine/Animator.h"

PlayerIdle::PlayerIdle()
{
    idleSpriteSheet.loadTexture("assets/textures/player/Idle.png");
    idleSpriteSheet.setDynamicPosition(&SINGLETON->gPlayer->position);
    
    animation = new Animator;
    animation->setFrameRate(4.f);
    animation->addSpriteSheet(&idleSpriteSheet, 2, 56, idleSpriteSheet.getHeight());
}

void PlayerIdle::updateState()
{
    BaseState::updateState();

    switch (SINGLETON->gPlayer->stateMachine->stateEnum)
    {
    case LEFT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->leftState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->rightState);
        break;
    case UP:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->downState);
        break;
    default
    : break;
    }
}

PlayerLeft::PlayerLeft()
{
    leftSpriteSheet.loadTexture("assets/textures/player/MoveRight_Left.png");
    leftSpriteSheet.setDynamicPosition(&SINGLETON->gPlayer->position);
    
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&leftSpriteSheet, 2, 56, leftSpriteSheet.getHeight());

    animation->flip(SDL_FLIP_HORIZONTAL);
}

void PlayerLeft::updateState()
{
    BaseState::updateState();

    switch (SINGLETON->gPlayer->stateMachine->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->idleState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->rightState);
        break;
    case UP:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->downState);
        break;
    default
    : break;
    }
}

PlayerRight::PlayerRight()
{
    rightSpriteSheet.loadTexture("assets/textures/player/MoveRight_Left.png");
    rightSpriteSheet.setDynamicPosition(&SINGLETON->gPlayer->position);
    
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&rightSpriteSheet, 2, 56, rightSpriteSheet.getHeight());
}

void PlayerRight::updateState()
{
    BaseState::updateState();

    switch (SINGLETON->gPlayer->stateMachine->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->idleState);
        break;
    case LEFT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->leftState);
        break;
    case UP:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->downState);
        break;
    default
    : break;
    }
}

PlayerUp::PlayerUp()
{
    upSpriteSheet.loadTexture("assets/textures/player/MoveUp.png");
    upSpriteSheet.setDynamicPosition(&SINGLETON->gPlayer->position);
    
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSpriteSheet(&upSpriteSheet, 2, 56, upSpriteSheet.getHeight());
}

void PlayerUp::updateState()
{
    BaseState::updateState();

    switch (SINGLETON->gPlayer->stateMachine->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->idleState);
        break;
    case LEFT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->leftState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->rightState);
        break;
    case DOWN:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->downState);
        break;
    default
    : break;
    }
}

PlayerDown::PlayerDown()
{
    downSpriteSheet.loadTexture("assets/textures/player/MoveDown.png");
    downSpriteSheet.setDynamicPosition(&SINGLETON->gPlayer->position);
    
    animation = new Animator;
    animation->setFrameRate(16.f);
    animation->addSpriteSheet(&downSpriteSheet, 5, 56, downSpriteSheet.getHeight());
}

void PlayerDown::updateState()
{
    BaseState::updateState();

    switch (SINGLETON->gPlayer->stateMachine->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->idleState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->rightState);
        break;
    case LEFT:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->leftState);
        break;
    case UP:
        SINGLETON->gPlayer->stateMachine->stateTransition(SINGLETON->gPlayer->stateMachine->upState);
        break;
    default
    : break;
    }
}
