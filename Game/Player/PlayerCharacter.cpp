#include "PlayerCharacter.h"

#include "../../../Engine/Singelton.h"
#include "../../Engine/Animator.h"
#include "AnimationStateMachine/PlayerASM.h"
#include "../../../Engine/Core/CollisionObject.h"

void PlayerCharacter::start()
{
    BaseCharacter::start();

    PLAYER = this;

    stateMachine = new PlayerASM;
    stateMachine->start();

    spriteHeight = static_cast<float>(stateMachine->currentState->animation->spriteSheet->getHeight());
    spriteWidth = static_cast<float>(stateMachine->currentState->animation->spriteSheet->getWidth());

    collision = new CollisionObject(this);
    collision->createCollisionShape(spriteHeight, spriteWidth - 10, &position);
    collision->updatePixelBorder();
}

void PlayerCharacter::update()
{
    BaseCharacter::update();

    if (attackCooldown > 0)
    {
        attackCooldown -= DELTA_TIME;
    }
}

void PlayerCharacter::close()
{
    BaseCharacter::close();

    stateMachine->close();
}

void PlayerCharacter::move()
{
    position = position + velocity * DELTA_TIME;

    //Map bounderies
    if (position.x - spriteWidth / 2 < 50.f)
    {
        position.x = 50.f + spriteWidth / 2;
    }
    if (position.x + spriteWidth / 2 > SINGLETON->SCREEN_WIDTH - 50.f)
    {
        position.x = SINGLETON->SCREEN_WIDTH - 50.f - spriteWidth / 2;
    }

    if (position.y - spriteHeight / 2 < 50.f)
    {
        position.y = 50.f + spriteHeight / 2;
    }
    if (position.y + spriteHeight / 2 > SINGLETON->SCREEN_HEIGHT - 50.f)
    {
        position.y = SINGLETON->SCREEN_HEIGHT - 50.f - spriteHeight / 2;
    }
}

PlayerCharacter::PlayerCharacter(Vector& spawnPos)
{
    position = spawnPos;
    name = typeid(this).name();
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
                velocity = moveDir.normalize() * movementSpeed;
                move();
            }
        }
        if (isShooting && attackCooldown <= 0.f)
        {
            if (!(aimDir.length() == 0.f))
            {
                attackCooldown = attackSpeed;
                Vector aimNormalized = aimDir.normalize();

                projectileSpawner.spawnProjectile(position, aimNormalized);
            }
        }
        aimDir.Zero();
        moveDir.Zero();
        velocity.Zero();
        isMoveing = false;
        isShooting = false;
    }
}

void PlayerCharacter::addMoveDirection(Vector& v)
{
    moveDir += v;
}

void PlayerCharacter::addAimDirection(Vector& v)
{
    aimDir += v;
}

void PlayerCharacter::disablePlayer()
{
    notify(PLAYER_DIED);
}
