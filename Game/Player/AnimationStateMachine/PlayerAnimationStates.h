#pragma once
#include "../../../Engine/Animation/Animator.h"
#include "../../../Engine/Animation/AnimationBaseState.h"

class PlayerIdle : public BaseState
{
    //Sprites
    Texture idleSpriteSheet;

    void updateState();

public:
    PlayerIdle();
};

class PlayerLeft : public BaseState
{
    Texture leftSpriteSheet;

public:
    PlayerLeft();

    void updateState() override;
};

class PlayerRight : public BaseState
{
    Texture rightSpriteSheet;

public:
    PlayerRight();

    void updateState() override;
};

class PlayerUp : public BaseState
{
    Texture upSpriteSheet;

public:
    PlayerUp();

    void updateState() override;
};

class PlayerDown : public BaseState
{
    Texture downSpriteSheet;

public:
    PlayerDown();

    void updateState() override;
};
