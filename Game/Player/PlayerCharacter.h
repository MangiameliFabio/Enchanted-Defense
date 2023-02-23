#pragma once
#include "../../Engine/Core/Object.h"
#include "../../Engine/Core/Patterns/Observer.h"
#include "../../Engine/Core/Texture.h"
#include "../../Engine/Core/Vector.h"
#include "../../Engine/Enums.h"

class Animator;
struct Vector;

class PlayerCharacter : public Object, public Observer
{
    void start() override;
    void update() override;
    void close() override;

    Animator* idleAnimation;
    Vector position = Vector();
    Vector moveDir = Vector();

    //Sprites
    Texture idle1;
    Texture idle2;

public:
    void move(Vector& dir);
    void onNotify(const Event event) override;
    void addMoveDirection(Vector& v);
    void createAnimations();

    PlayerCharacter(Vector& spawnPos);
    ~PlayerCharacter();

    float movementSpeed = 200.f;

    bool isMoveing = false;
    bool isShooting = false;
};
