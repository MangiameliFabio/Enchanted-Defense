﻿#include "Object.h"

#include "..\EngineSingelton.h"

void Object::init()
{
}

void Object::update()
{
}

void Object::close()
{
    if (!queuedForDelete)
    {
        queuedForDelete = true;
        ENGINE->removeObject(this);
        ENGINE->addToDeleteQueue(this);
    }
}

Object::Object()
{
    ENGINE->addObject(this);
}

Object::~Object()
{
}
