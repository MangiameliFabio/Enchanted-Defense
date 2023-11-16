#include "Object.h"

#include "..\EngineSingelton.h"

void Object::init()
{
}

void Object::update()
{
}

void Object::close()
{
    markForDelete();
}

void Object::markForDelete()
{
    queuedForDelete = true;
    ENGINE->removeObject(this);
    ENGINE->addToDeleteQueue(this);
}

Object::Object()
{
    ENGINE->addObject(this);
    name = typeid(this).name();
}

Object::~Object()
{
}
