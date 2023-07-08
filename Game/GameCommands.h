#pragma once
#pragma once
#include "../Engine/Core/Patterns/Command.h"
#include "..\Engine\EngineSingelton.h"

class CloseGameCommand : public Command
{
public:
    virtual void execute()
    {
        ENGINE->gQuit = true;
    }
};
