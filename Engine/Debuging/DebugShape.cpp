#include "DebugShape.h"

#include "..\EngineSingelton.h"

DebugShape::DebugShape()
{
    ENGINE->gRenderer->addDebugShape(this);
}

DebugShape::~DebugShape()
{
    ENGINE->gRenderer->removeDebugShape(this);
}

void DebugShape::render()
{
}
