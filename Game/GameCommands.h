#pragma once
#pragma once
#include "../Engine/Command.h"
#include "../Engine/Singelton.h"

class CloseGameCommand : public Command
{
public:
    virtual void execute()
    {
        SINGLETON->quit = true;
    }
};
