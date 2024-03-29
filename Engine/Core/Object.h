﻿#pragma once
#include <string>

#include "Vector.h"

struct Vector;

class Object
{
public:

    virtual void init();
    virtual void update();
    virtual void close();
    virtual void markForDelete();

    Object();
    virtual ~Object();
    Vector velocity;

    std::string name = "invalid Name";
    
    bool shouldUpdate = true;
    bool queuedForDelete = false;
};
