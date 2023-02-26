#pragma once
#include <vector>

#include "../BaseCharacter.h"
#include "../BaseEnemy.h"
#include "../../Engine/Animator.h"

class SkeletonCharacter : public BaseEnemy
{
    void update() override;

public:
    SkeletonCharacter(Vector& spawnPosition);
    ~SkeletonCharacter() override;
    
    void move();
    void close() override;
    bool checkForCollision();

    std::vector<Vector> path;
    std::vector<BaseCharacter*> nearCharacter;

    Texture spriteSheet;
    Animator animation;
    Vector lastValidPos;

    float pfCooldown = 0.5f;
    float pfCurrentCooldown = 0.f;
    float movementSpeed = 100.f;

    bool isMoving = true;
};
