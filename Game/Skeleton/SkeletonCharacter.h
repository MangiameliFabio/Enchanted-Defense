#pragma once

#include <vector>

#include "../BaseCharacter.h"
#include "../BaseEnemy.h"
#include "../../Engine/Animation/Animator.h"
#include "../../Engine/Core/Patterns/Observer.h"

class SoundEffect;

class SkeletonCharacter : public BaseEnemy, public Observer
{
    void update() override;

public:
    SkeletonCharacter(const Vector& spawnPosition);
    ~SkeletonCharacter() override;

    void move();
    void close() override;
    bool checkForCollision();
    bool setDirToPath();

    void onDeath() const override;
    
    void onNotify(const EEvent event) override;

    std::vector<Vector> path;
    std::vector<BaseCharacter*> nearCharacter;
    
    std::shared_ptr<Animator> animation = nullptr;

    Vector lastValidPos;

    float pfCooldown = 0.5f;
    float pfCurrentCooldown = 0.f;
    float movementSpeed = 60.f;

    bool isMoving = true;
};
