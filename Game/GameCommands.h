#pragma once
#pragma once
#include "../Engine/Core/Patterns/Command.h"
#include "../Engine/Singelton.h"

class CloseGameCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->gQuit = true;
    }
};
