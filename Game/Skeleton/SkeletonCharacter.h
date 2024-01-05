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
    SkeletonCharacter(Vector& spawnPosition);
    ~SkeletonCharacter() override;

    void move();
    void close() override;
    bool checkForCollision();
    bool setDirToPath();

    void onDeath() const override;
    
    void onNotify(const Event event) override;

    std::vector<Vector> path;
    std::vector<BaseCharacter*> nearCharacter;
    
    std::shared_ptr<Animator> animation = nullptr;
    std::shared_ptr<SoundEffect> deathSound = nullptr;

    Vector lastValidPos;

    float pfCooldown = 0.5f;
    float pfCurrentCooldown = 0.f;
    float movementSpeed = 50.f;

    bool isMoving = true;
};
