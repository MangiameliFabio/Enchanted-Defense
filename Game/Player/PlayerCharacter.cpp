#include "PlayerCharacter.h"

#include "../../../Engine/Singelton.h"
#include "../../Engine/Animator.h"

void PlayerCharacter::start()
{
    Object::start();
    SINGLETON->gPlayer = this;
    playerASM = new PlayerASM;
    playerASM->start();
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
    printf("Player created \n");

    position = spawnPos;
}

PlayerCharacter::~PlayerCharacter()
{
    printf("Player has been deleted \n");
}

void PlayerCharacter::onNotify(const Event event)
{
    if (event == ALL_INPUTS_HANDLED)
    {
        if (isMoveing)
        {
            if (!(moveDir.length() == 0.f))
            {
                Vector dirNormalized = moveDir.normalize();
                move(dirNormalized);
            }
            isMoveing = false;
            moveDir.Zero();
        }
    }
}

void PlayerCharacter::addMoveDirection(Vector& v)
{
    moveDir += v;
}
