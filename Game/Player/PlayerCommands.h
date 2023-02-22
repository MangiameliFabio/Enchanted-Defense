#pragma once
#include "../../Engine/Command.h"
#include "../../Engine/Singelton.h"

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(-1, 0);
        SINGLETON->Player->addMoveDirection(dir);
        SINGLETON->Player->isMoveing = true;
    }
};

class MoveRightCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(1, 0);

        SINGLETON->Player->addMoveDirection(dir);
        SINGLETON->Player->isMoveing = true;
    }
};

class MoveUpCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, -1);

        SINGLETON->Player->addMoveDirection(dir);
        SINGLETON->Player->isMoveing = true;
    }
};

class MoveDownCommand : public Command
{
public:
    virtual void execute()
    {
        Vector dir = Vector(0, 1);

        SINGLETON->Player->addMoveDirection(dir);
        SINGLETON->Player->isMoveing = true;
    }
};
