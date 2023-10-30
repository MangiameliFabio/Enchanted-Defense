﻿#pragma once

#include "../Engine/Core/CollisionObject.h"
#include "../Engine/Core/Object.h"
#include "../Engine/Core/Vector.h"

class BaseCharacter : public Object
{
public:
    BaseCharacter();
    ~BaseCharacter() override = default;

    Vector position;
    Vector moveDir;

    CollisionObject collision;
};
