#pragma once
#include "Object.h"

class Command
{
public:
    virtual ~Command(){}

    virtual void execute() = 0;
};
