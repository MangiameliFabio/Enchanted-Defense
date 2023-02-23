#include "PlayerCharacter.h"

#include "../../../Engine/Singelton.h"
#include "../../Engine/Animator.h"

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
    printf("Player created \n");
    SINGLETON->gPlayer = this;

    position = spawnPos;

    createAnimations();
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

void PlayerCharacter::createAnimations()
{
    //Piskel x4
    idle1.loadTexture("assets/textures/player/idle/idle1.png");
    idle1.setDynamicPosition(&position);
    idle2.loadTexture("assets/textures/player/idle/idle2.png");
    idle2.setDynamicPosition(&position);

    idleAnimation = new Animator();
    idleAnimation->setFrameRate(4.f);
    idleAnimation->addSprite(&idle1);
    idleAnimation->addSprite(&idle2);
}
