#pragma once
#include "../../../Engine/Animation/Animator.h"
#include "../../../Engine/Animation/AnimationBaseState.h"

class PlayerIdle : public BaseState
{
    void updateState();

public:
    PlayerIdle();
};

class PlayerLeft : public BaseState
{
public:
    PlayerLeft();

    void updateState() override;
};

class PlayerRight : public BaseState
{
public:
    PlayerRight();

    void updateState() override;
};

class PlayerUp : public BaseState
{
public:
    PlayerUp();

    void updateState() override;
};

class PlayerDown : public BaseState
{
public:
    PlayerDown();

    void updateState() override;
};
