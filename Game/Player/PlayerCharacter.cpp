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

void PlayerCharacter::move(Vector& dir)
{
    position = position + dir * movementSpeed * SINGLETON->gDeltaTime;
}

PlayerCharacter::PlayerCharacter(Vector& spawnPos)
{
    printf("Player created");
    SINGLETON->Player = this;

    position = spawnPos;

    playerTexture.loadTexture("assets/textures/player/Player.png");
    playerTexture.setDynamicX(&position.x);
    playerTexture.setDynamicY(&position.y);
}

PlayerCharacter::~PlayerCharacter()
{
    printf("Player has been deleted");
}

void PlayerCharacter::onNotify(const Event event)
{
    if (event == ALL_INPUTS_HANDLED)
    {
        if (isMoveing)
        {
            Vector dirNormalized = moveDir.normalize();
            move(dirNormalized);
            isMoveing = false;
            moveDir.Zero();
        }
    }
}

void PlayerCharacter::addMoveDirection(Vector& v)
{
    moveDir += v;
}
