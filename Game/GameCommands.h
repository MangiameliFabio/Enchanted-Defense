#pragma once
#include "../Engine/EngineSingelton.h"
#include "../Engine/Core/Patterns/Command.h"

class CloseGameCommand : public Command
{
public:
    virtual void execute()
    {
        ENGINE->gQuit = true;
    }
};
