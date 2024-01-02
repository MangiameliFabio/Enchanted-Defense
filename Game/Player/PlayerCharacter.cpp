#include "PlayerCharacter.h"

#include <memory>

#include "InputManager.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Animation/Animator.h"
#include "AnimationStateMachine/PlayerASM.h"
#include "../../../Engine/Core/CollisionObject.h"
#include "../Projectile.h"

void PlayerCharacter::init()
{
    BaseCharacter::init();
    
    ENGINE->addObserver(this);

    inputManager = std::make_shared<InputManager>();
    inputManager->init();
    stateMachine = std::make_shared<PlayerASM>();
    stateMachine->init();

    spriteHeight = static_cast<float>(stateMachine->currentState->animation->getSpriteSheet()->getHeight());
    spriteWidth = static_cast<float>(stateMachine->currentState->animation->getSpriteSheet()->getWidth());
    
    collision->createCollisionShape(spriteHeight, spriteWidth - 10, &position);
    collision->updatePixelBorder();
}

void PlayerCharacter::update()
{
    BaseCharacter::update();

    stateMachine->update();

    if (attackCooldown > 0)
    {
        attackCooldown -= DELTA_TIME;
    }
}

void PlayerCharacter::close()
{
    BaseCharacter::close();
    
    
}

void PlayerCharacter::move()
{
    position = position + velocity * DELTA_TIME;

    //Map bounderies
    if (position.x - spriteWidth / 2 < 50.f)
    {
        position.x = 50.f + spriteWidth / 2;
    }
    if (position.x + spriteWidth / 2 > ENGINE->SCREEN_WIDTH - 50.f)
    {
        position.x = ENGINE->SCREEN_WIDTH - 50.f - spriteWidth / 2;
    }

    if (position.y - spriteHeight / 2 < 50.f)
    {
        position.y = 50.f + spriteHeight / 2;
    }
    if (position.y + spriteHeight / 2 > ENGINE->SCREEN_HEIGHT - 50.f)
    {
        position.y = ENGINE->SCREEN_HEIGHT - 50.f - spriteHeight / 2;
    }
}

void PlayerCharacter::spawnProjectile(Vector& pos, Vector& dir)
{
    new Projectile(pos, dir);
}

PlayerCharacter::PlayerCharacter(): BaseCharacter()
{
}

PlayerCharacter::~PlayerCharacter()
{
    ENGINE->removeObserver(this);

    printf("Player has been deleted \n");
}

void PlayerCharacter::onNotify(const Event event)
{
    if (event == HANDLE_INPUT)
        inputManager->handleInput();

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

                spawnProjectile(position, aimNormalized);
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

void PlayerCharacter::die()
{
    notify(PLAYER_DIED);
}
