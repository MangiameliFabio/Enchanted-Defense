#include "DebugShape.h"

#include "../Singelton.h"

DebugShape::DebugShape()
{
    SINGLETON->gRenderer->addDebugShape(this);
}

DebugShape::~DebugShape()
{
    SINGLETON->gRenderer->removeDebugShape(this);
}

void DebugShape::render()
{
}
