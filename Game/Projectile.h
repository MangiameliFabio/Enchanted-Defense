#pragma once
#include "../Engine/Core/CollisionObject.h"
#include "../Engine/Core/Object.h"
#include "../Engine/Core/Texture.h"
#include "../Engine/Core/Vector.h"

class Projectile : public Object
{
    void update() override;

public:
    Projectile(const Vector& pos_, const Vector& dir_);
    ~Projectile() override = default;

    void close() override;

    CollisionObject* projectileCollision;

    Vector dir;
    Vector pos;

    Texture texture;

    float projectileSpeed = 500;
};
