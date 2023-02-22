#include "PlayerCharacter.h"

#include "../../Engine/Singelton.h"

void PlayerCharacter::start()
{
    Object::start();
}

void PlayerCharacter::update()
{
    Object::update();
}

void PlayerCharacter::close()
{
    Object::close();
}

void PlayerCharacter::move(float xDir, float yDir)
{
    x += xDir * SINGLETON->gDeltaTime * movementSpeed;
    y += yDir * SINGLETON->gDeltaTime * movementSpeed;
}

PlayerCharacter::PlayerCharacter(float _x, float _y)
{
    printf("Player created");
    SINGLETON->Player = this;

    x = _x;
    y = _y;

    playerTexture.loadTexture("assets/textures/player/Player.png");
    playerTexture.setDynamicX(&x);
    playerTexture.setDynamicY(&y);
}

PlayerCharacter::~PlayerCharacter()
{
    printf("Player has been deleted");
}
