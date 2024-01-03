#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
    collision = std::make_shared<CollisionObject>();
    collision->init(this);
}

void BaseCharacter::update()
{
    Object::update();
}
