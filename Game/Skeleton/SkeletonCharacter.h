#pragma once
#include <vector>

#include "../BaseCharacter.h"
#include "../BaseEnemy.h"
#include "../../Engine/Animator.h"
#include "../../Engine/Core/Patterns/Observer.h"

class SkeletonCharacter : public BaseEnemy, public Observer
{
    void update() override;

public:
    SkeletonCharacter(Vector& spawnPosition);
    ~SkeletonCharacter() override;

    void move();
    void close() override;
    bool checkForCollision();
    bool setDirToPath();
    
    void onNotify(const Event event) override;

    std::vector<Vector> path;
    std::vector<BaseCharacter*> nearCharacter;

    Texture spriteSheet;
    Animator animation;
    Vector lastValidPos;

    float pfCooldown = 0.5f;
    float pfCurrentCooldown = 0.f;
    float movementSpeed = 50.f;

    bool isMoving = true;

};
