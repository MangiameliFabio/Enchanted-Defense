#include "SkeletonCharacter.h"

#include "../../Engine/Singelton.h"

SkeletonCharacter::SkeletonCharacter(Vector& SpawnPosition)
{
    //Set spawn Position
    position = SpawnPosition;

    //Load sprite sheet
    spriteSheet.loadTexture("assets/textures/enemies/skeleton.png");
    spriteSheet.setDynamicPosition(&position);

    //Create Animation
    animation.addSpriteSheet(&spriteSheet, 4, 36, spriteSheet.getHeight());
    animation.enable();
    animation.setFrameRate(8.f);

    collision = new CollisionObject;
    collision->createCollisionShape(spriteSheet.getHeight(), spriteSheet.getWidth(), &position);
}

SkeletonCharacter::~SkeletonCharacter()
{
}

void SkeletonCharacter::update()
{
    BaseCharacter::update();

    isMoving = true;
    if (!SINGLETON->pathfindingGrid->findPath(position, SINGLETON->gPlayer->position, path))
    {
        isMoving = false;
    }

    if (isMoving)
        move();

    animation.update();
}

void SkeletonCharacter::move()
{
    Vector dir = (path.top() - position).normalize();
    position = position + dir * movementSpeed * SINGLETON->gDeltaTime;

    if (Vector::dist(path.top(), position) <= 20.f)
    {
        if (!path.empty())
        {
            path.pop();
        }
    }
}
