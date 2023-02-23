#pragma once
#include "../../Enums.h"

class Observer
{
public:
    virtual ~Observer() {}

    virtual void onNotify(const Event event) = 0;
};
