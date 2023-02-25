#pragma once
#include "../Engine/Core/Object.h"
#include "../Engine/Core/Vector.h"

class CollisionObject;
class AnimationStateMachine;

class BaseCharacter : public Object
{
public:
    Vector position;
    Vector moveDir;

    CollisionObject* collision;
};
