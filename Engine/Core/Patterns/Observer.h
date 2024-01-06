#pragma once

#include "../../Enums.h"

class Observer
{
public:
    virtual ~Observer() = default;

    virtual void onNotify(const EEvent event) = 0;
};
