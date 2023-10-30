#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
    name = typeid(this).name();

    collision.init(this);
}
