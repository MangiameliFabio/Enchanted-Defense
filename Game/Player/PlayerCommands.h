#pragma once
#include "../../Engine/Core/Patterns/Command.h"
#include "../../Engine/Singelton.h"

class PlayerASM;
class AnimationSubject;

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
        static_cast<PlayerASM*>(SINGLETON->gPlayer->stateMachine)->stateEnum = LEFT;
    }
};

class MoveRightCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(1, 0);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
        SINGLETON->gPlayer->stateMachine->stateEnum = RIGHT;
    }
};

class MoveUpCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, -1);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
        SINGLETON->gPlayer->stateMachine->stateEnum = UP;
    }
};

class MoveDownCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, 1);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
        SINGLETON->gPlayer->stateMachine->stateEnum = DOWN;
    }
};

class AimLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);

        SINGLETON->gPlayer->addAimDirection(dir);
        SINGLETON->gPlayer->isShooting = true;
    }
};

class AimRightCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(1, 0);

        SINGLETON->gPlayer->addAimDirection(dir);
        SINGLETON->gPlayer->isShooting = true;
    }
};

class AimUpCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, -1);

        SINGLETON->gPlayer->addAimDirection(dir);
        SINGLETON->gPlayer->isShooting = true;
    }
};

class AimDownCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, 1);

        SINGLETON->gPlayer->addAimDirection(dir);
        SINGLETON->gPlayer->isShooting = true;
    }
};
