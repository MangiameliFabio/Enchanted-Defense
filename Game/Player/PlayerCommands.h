#pragma once
#include "../../Engine/Command.h"
#include "../../Engine/Singelton.h"

class MoveLeftCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->Player->move(-1, 0);
    }
};

class MoveRightCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->Player->move(1, 0);
    }
};

class MoveUpCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->Player->move(0, -1);
    }
};

class MoveDownCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->Player->move(0, 1);
    }
};
