#include "Object.h"

#include "Singelton.h"

Object::Object()
{
    SINGLETON->updateFunctions.push_back(this);
}

void Object::start()
{
}

void Object::update()
{
}

void Object::close()
{
}
