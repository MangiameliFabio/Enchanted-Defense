#pragma once

#include "../BaseCharacter.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Core/Vector.h"
#include "../../Engine/Enums.h"
#include "../../Engine/Core/Patterns/Subject.h"
#include "AnimationStateMachine/PlayerASM.h"

class InputManager;
class Animator;
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
    void disablePlayer();

    PlayerCharacter(Vector& spawnPos);
    ~PlayerCharacter() override;

    PlayerASM* stateMachine{};
    InputManager* inputManager;

    Vector aimDir;

    float spriteHeight{};
    float spriteWidth{};

    float movementSpeed = 150.f;
    float attackSpeed = 0.5f;
    float attackCooldown = 0.f;

    bool isMoveing = false;
    bool isShooting = false;
};
