#pragma once
#include <stack>

#include "../BaseCharacter.h"
#include "../BaseEnemy.h"
#include "../../Engine/Animator.h"
#include "../../Engine/Core/CollisionObject.h"

class SkeletonCharacter : public BaseEnemy
{
public:
    SkeletonCharacter(Vector& spawnPosition);
    ~SkeletonCharacter() override;

    std::stack<Vector> path;

    Texture spriteSheet;
    Animator animation;

    //Maybe add if performance is to poor
    // float pfCooldown = 0.5f;
    // float pfCurrentCooldown = 0.f;
    float movementSpeed = 100.f;

    bool isMoving = true;

    void update() override;

    void move();
};
