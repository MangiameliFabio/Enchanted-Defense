#pragma once
#include "../../Engine/Core/Patterns/Command.h"
#include "../../Engine/Singelton.h"

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);

        SINGLETON->gPlayer->addMoveDirection(dir);
        SINGLETON->gPlayer->isMoveing = true;
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
    }
};
