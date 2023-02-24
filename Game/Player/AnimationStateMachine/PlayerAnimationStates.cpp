#include "PlayerAnimationStates.h"
#include "../../../Engine/Singelton.h"
#include "../../../Engine/Animator.h"


PlayerBaseState::~PlayerBaseState()
{
}

void PlayerBaseState::startState()
{
    if(!animation)
    {
        printf("Can't start State animation is invalid");
        return;
    }
    animation->enable();
}

void PlayerBaseState::updateState()
{
    if(!animation)
    {
        printf("Can't update State animation is invalid");
        return;
    }
    animation->update();
}

void PlayerBaseState::endState()
{
    if(!animation)
    {
        printf("Can't end State animation is invalid");
        return;
    }
    animation->disable();
}

PlayerIdle::PlayerIdle()
{
    //Load Idle Animation Sprites
    idle0.loadTexture("assets/textures/player/idle/idle0.png");
    idle0.setDynamicPosition(&SINGLETON->gPlayer->position);
    idle1.loadTexture("assets/textures/player/idle/idle1.png");
    idle1.setDynamicPosition(&SINGLETON->gPlayer->position);
    //Create Animator for Idle
    animation = new Animator;
    animation->setFrameRate(4.f);
    animation->addSprite(&idle0);
    animation->addSprite(&idle1);
}

void PlayerIdle::updateState()
{
    PlayerBaseState::updateState();

    switch (SINGLETON->gPlayer->playerASM->stateEnum)
    {
    case LEFT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->leftState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->rightState);
        break;
    case UP:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->downState);
        break;
    default
    : break;
    }
}

PlayerLeft::PlayerLeft()
{
    //Load Animation for left and right movement Sprites
    left0.loadTexture("assets/textures/player/leftRight/leftRight1.png");
    left0.setDynamicPosition(&SINGLETON->gPlayer->position);
    left1.loadTexture("assets/textures/player/leftRight/leftRight2.png");
    left1.setDynamicPosition(&SINGLETON->gPlayer->position);
    left2.loadTexture("assets/textures/player/leftRight/leftRight3.png");
    left2.setDynamicPosition(&SINGLETON->gPlayer->position);
    //Create Animator for left and right movement
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSprite(&left0);
    animation->addSprite(&left1);
    animation->addSprite(&left2);

    animation->flip(SDL_FLIP_HORIZONTAL);
}

void PlayerLeft::updateState()
{
    PlayerBaseState::updateState();

    switch (SINGLETON->gPlayer->playerASM->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->idleState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->rightState);
        break;
    case UP:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->downState);
        break;
    default
    : break;
    }
}

PlayerRight::PlayerRight()
{
    //Load Animation for left and right movement Sprites
    right0.loadTexture("assets/textures/player/leftRight/leftRight1.png");
    right0.setDynamicPosition(&SINGLETON->gPlayer->position);
    right1.loadTexture("assets/textures/player/leftRight/leftRight2.png");
    right1.setDynamicPosition(&SINGLETON->gPlayer->position);
    right2.loadTexture("assets/textures/player/leftRight/leftRight3.png");
    right2.setDynamicPosition(&SINGLETON->gPlayer->position);
    //Create Animator for left and right movement
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSprite(&right0);
    animation->addSprite(&right1);
    animation->addSprite(&right2);
}

void PlayerRight::updateState()
{
    PlayerBaseState::updateState();

    switch (SINGLETON->gPlayer->playerASM->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->idleState);
        break;
    case LEFT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->leftState);
        break;
    case UP:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->upState);
        break;
    case DOWN:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->downState);
        break;
    default
    : break;
    }
}

PlayerUp::PlayerUp()
{
    //Load Animation for left and right movement Sprites
    up0.loadTexture("assets/textures/player/up/up0.png");
    up0.setDynamicPosition(&SINGLETON->gPlayer->position);
    up1.loadTexture("assets/textures/player/up/up1.png");
    up1.setDynamicPosition(&SINGLETON->gPlayer->position);
    up2.loadTexture("assets/textures/player/up/up2.png");
    up2.setDynamicPosition(&SINGLETON->gPlayer->position);
    up3.loadTexture("assets/textures/player/up/up3.png");
    up3.setDynamicPosition(&SINGLETON->gPlayer->position);
    //Create Animator for left and right movement
    animation = new Animator;
    animation->setFrameRate(8.f);
    animation->addSprite(&up0);
    animation->addSprite(&up1);
    animation->addSprite(&up2);
    animation->addSprite(&up3);
}

void PlayerUp::updateState()
{
    PlayerBaseState::updateState();

    switch (SINGLETON->gPlayer->playerASM->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->idleState);
        break;
    case LEFT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->leftState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->rightState);
        break;
    case DOWN:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->downState);
        break;
    default
    : break;
    }
}

PlayerDown::PlayerDown()
{
    //Load Animation for left and right movement Sprites
    down0.loadTexture("assets/textures/player/down/down0.png");
    down0.setDynamicPosition(&SINGLETON->gPlayer->position);
    down1.loadTexture("assets/textures/player/down/down1.png");
    down1.setDynamicPosition(&SINGLETON->gPlayer->position);
    down2.loadTexture("assets/textures/player/down/down2.png");
    down2.setDynamicPosition(&SINGLETON->gPlayer->position);
    down3.loadTexture("assets/textures/player/down/down3.png");
    down3.setDynamicPosition(&SINGLETON->gPlayer->position);
    down4.loadTexture("assets/textures/player/down/down4.png");
    down4.setDynamicPosition(&SINGLETON->gPlayer->position);
    down5.loadTexture("assets/textures/player/down/down5.png");
    down5.setDynamicPosition(&SINGLETON->gPlayer->position);
    down6.loadTexture("assets/textures/player/down/down6.png");
    down6.setDynamicPosition(&SINGLETON->gPlayer->position);

    //Create Animator for left and right movement
    animation = new Animator;
    animation->setFrameRate(14.f);
    animation->addSprite(&down0);
    animation->addSprite(&down1);
    animation->addSprite(&down2);
    animation->addSprite(&down3);
    animation->addSprite(&down4);
    animation->addSprite(&down5);
    animation->addSprite(&down6);
}

void PlayerDown::updateState()
{
    PlayerBaseState::updateState();

    switch (SINGLETON->gPlayer->playerASM->stateEnum)
    {
    case IDLE:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->idleState);
        break;
    case RIGHT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->rightState);
        break;
    case LEFT:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->leftState);
        break;
    case UP:
        SINGLETON->gPlayer->playerASM->stateTransition(SINGLETON->gPlayer->playerASM->upState);
        break;
    default
    : break;
    }
}
