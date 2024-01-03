#pragma once

#include "../Engine/Core/CollisionObject.h"
#include "../Engine/Core/Object.h"
#include "../Engine/Core/Vector.h"

class BaseCharacter : public Object
{
public:
    BaseCharacter();
    ~BaseCharacter() override = default;

    void update() override;

    Vector position;
    Vector moveDir;

    std::shared_ptr<CollisionObject> collision;
};
