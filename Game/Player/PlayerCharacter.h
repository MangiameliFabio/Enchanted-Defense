#pragma once

#include "../BaseCharacter.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Core/Patterns/Subject.h"

#include "AnimationStateMachine/PlayerASM.h"
#include "InputManager.h"

class SoundEffect;
struct Vector;

class PlayerCharacter : public BaseCharacter, public Observer, public Subject
{
public:
    void init() override;
    void update() override;
    void close() override;

    void move();
    void spawnProjectile(Vector& pos, Vector& dir);
    void onNotify(const Event event) override;
    void addMoveDirection(Vector& v);
    void addAimDirection(Vector& v);
    void die();

    PlayerCharacter();
    ~PlayerCharacter() override;

    std::shared_ptr<PlayerASM> stateMachine = nullptr;
    std::shared_ptr<InputManager> inputManager = nullptr;

    std::shared_ptr<SoundEffect> shootSound = nullptr;
    std::shared_ptr<SoundEffect> gameOver = nullptr;

    Vector aimDir = {0,0};

    float spriteHeight = 0.f;
    float spriteWidth = 0.f;

    float movementSpeed = 150.f;
    float attackSpeed = 0.5f;
    float attackCooldown = 0.f;

    bool isMoving = false;
    bool isShooting = false;
};
