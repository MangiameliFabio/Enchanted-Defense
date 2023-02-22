#pragma once
#include "../../Engine/Object.h"
#include "../../Engine/Observer.h"
#include "../../Engine/Texture.h"
#include "../../Engine/Vector.h"

struct Vector;

class PlayerCharacter : public Object, public Observer
{
    void start() override;
    void update() override;
    void close() override;

    Texture playerTexture;
    Vector position = Vector();
    Vector moveDir = Vector();

public:
    void move(Vector& dir);
    void onNotify(const Event event) override;
    void addMoveDirection(Vector& v);

    PlayerCharacter(Vector& spawnPos);
    ~PlayerCharacter();

    float movementSpeed = 100.f;

    bool isMoveing = false;
    bool isShooting = false;
};
