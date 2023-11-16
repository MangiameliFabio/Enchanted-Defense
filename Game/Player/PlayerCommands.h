#pragma once
#include "../GameSingleton.h"
#include "../../Engine/Core/Patterns/Command.h"

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);
        
        GameSingleton::getInstance()->gPlayer->addMoveDirection(dir);
        PLAYER->isMoveing = true;
        PLAYER->stateMachine->stateEnum = LEFT;
    }
};

class MoveRightCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(1, 0);

        PLAYER->addMoveDirection(dir);
        PLAYER->isMoveing = true;
        PLAYER->stateMachine->stateEnum = RIGHT;
    }
};

class MoveUpCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, -1);

        PLAYER->addMoveDirection(dir);
        PLAYER->isMoveing = true;
        PLAYER->stateMachine->stateEnum = UP;
    }
};

class MoveDownCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, 1);

        PLAYER->addMoveDirection(dir);
        PLAYER->isMoveing = true;
        PLAYER->stateMachine->stateEnum = DOWN;
    }
};

class AimLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);

        PLAYER->addAimDirection(dir);
        PLAYER->isShooting = true;
    }
};

class AimRightCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(1, 0);

        PLAYER->addAimDirection(dir);
        PLAYER->isShooting = true;
    }
};

class AimUpCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, -1);

        PLAYER->addAimDirection(dir);
        PLAYER->isShooting = true;
    }
};

class AimDownCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, 1);

        PLAYER->addAimDirection(dir);
        PLAYER->isShooting = true;
    }
};
