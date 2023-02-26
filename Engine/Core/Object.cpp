#include "Object.h"

#include "../Singelton.h"

void Object::start()
{
}

void Object::update()
{
}

void Object::close()
{
    queuedForDelete = true;
    SINGLETON->removeObject(this);
    SINGLETON->addToDeleteQueue(this);
}

Object::Object()
{
    SINGLETON->addObject(this);
}

Object::~Object()
{
}
