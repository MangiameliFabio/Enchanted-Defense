#pragma once

#include "../../Engine/Core/Object.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Core/Vector.h"
#include "../../Engine/Enums.h"
#include "AnimationStateMachine/PlayerASM.h"

class Animator;
struct Vector;

class PlayerCharacter : public Object, public Observer
{
public:
    void start() override;
    void update() override;
    void close() override;

    void move(Vector& dir);
    void onNotify(const Event event) override;
    void addMoveDirection(Vector& v);

    PlayerCharacter(Vector& spawnPos);
    ~PlayerCharacter();

    Vector position = Vector();

    float movementSpeed = 150.f;
    Vector moveDir = Vector();

    bool isMoveing = false;
    bool isShooting = false;

    PlayerASM* playerASM;
};
