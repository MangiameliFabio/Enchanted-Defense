#include "CollisionObject.h"

#include "../Singelton.h"

bool CollisionObject::checkForIntersection(CollisionObject* otherObject)
{
    updatePosition();
    otherObject->updatePosition();

    if (otherObject->topLeft.x >= bottomRight.x         //Checks the right
        || otherObject->bottomRight.x <= topLeft.x      //Checks the left
        || otherObject->topLeft.y >= bottomRight.y      //Checks the bottom
        || otherObject->bottomRight.y <= topLeft.y)     //Checks the top
        return false;

    printf("Collision");
    return true;
}

void CollisionObject::createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter)
{
    height = shapeHeight;
    width = shapeWidth;

    center = shapeCenter;
}

void CollisionObject::updatePosition()
{
    topLeft.x = center->x - width / 2;
    topLeft.y = center->y - height / 2;
    bottomRight.x = center->x + width / 2;
    bottomRight.y = center->y + height / 2;
}
