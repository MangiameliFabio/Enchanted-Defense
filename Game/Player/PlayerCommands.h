#pragma once
#include "../../Engine/Core/Patterns/Command.h"
#include "../../Engine/Singelton.h"

class AnimationSubject;

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
        SINGLETON->gPlayer->playerASM->stateEnum = LEFT;
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
        SINGLETON->gPlayer->playerASM->stateEnum = RIGHT;
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
        SINGLETON->gPlayer->playerASM->stateEnum = UP;
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
        SINGLETON->gPlayer->playerASM->stateEnum = DOWN;
    }
};
