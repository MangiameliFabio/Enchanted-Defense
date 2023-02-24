#pragma once
#include "PlayerASM.h"
#include "../../../Engine/Animator.h"

class PlayerBaseState
{
public:
    virtual ~PlayerBaseState();

    virtual void startState();
    virtual void updateState();
    virtual void endState();

    Animator* animation = nullptr;
};

class PlayerIdle : public PlayerBaseState
{
    //Sprites
    Texture idle0;
    Texture idle1;

    void updateState();

public:
    PlayerIdle();
};

class PlayerLeft : public PlayerBaseState
{
    Texture left0;
    Texture left1;
    Texture left2;
    Texture left3;

public:
    PlayerLeft();

    void updateState() override;
};

class PlayerRight : public PlayerBaseState
{
    Texture right0;
    Texture right1;
    Texture right2;
    Texture right3;

public:
    PlayerRight();

    void updateState() override;
};

class PlayerUp : public PlayerBaseState
{
    Texture up0;
    Texture up1;
    Texture up2;
    Texture up3;

public:
    PlayerUp();

    void updateState() override;
};

class PlayerDown : public PlayerBaseState
{
    Texture down0;
    Texture down1;
    Texture down2;
    Texture down3;
    Texture down4;
    Texture down5;
    Texture down6;

public:
    PlayerDown();

    void updateState() override;
};
