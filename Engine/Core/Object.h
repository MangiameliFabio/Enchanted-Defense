#pragma once
#include <string>

#include "Vector.h"

struct Vector;

class Object
{
public:
    bool shouldUpdate = true;
    bool queuedForDelete = false;

    std::string name = "invalid Name";

    virtual void start();
    virtual void update();
    virtual void close();

    Object();
    virtual ~Object();
};
