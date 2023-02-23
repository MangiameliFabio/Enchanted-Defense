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
}

Object::Object()
{
    SINGLETON->addObject(this);
}

Object::~Object()
{
    SINGLETON->removeObject(this);
}
