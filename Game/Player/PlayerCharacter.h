#pragma once
#include "../../Engine/Object.h"
#include "../../Engine/Texture.h"

class PlayerCharacter : Object
{
    Texture playerTexture;

    void start() override;
    void update() override;
    void close() override;

public:
    void move(float xDir,float yDir);

    PlayerCharacter(float _x, float _y);
    ~PlayerCharacter();
    
    float x;
    float y;
    float movementSpeed = 100.f;
};
