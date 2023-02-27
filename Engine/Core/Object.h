#pragma once
#include <string>

#include "Vector.h"

struct Vector;

class Object
{
public:

    virtual void start();
    virtual void update();
    virtual void close();

    Object();
    virtual ~Object();
    Vector velocity;

    std::string name = "invalid Name";
    
    bool shouldUpdate = true;
    bool queuedForDelete = false;
};
