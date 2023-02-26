#include "CollisionObject.h"

#include "MeasurePerformance.h"
#include "../Pathfinding.h"

bool CollisionObject::checkForIntersection(CollisionObject* otherObject)
{
    updatePosition();
    otherObject->updatePosition();

    if (otherObject->topLeft.x >= bottomRight.x //Checks the right
        || otherObject->bottomRight.x <= topLeft.x //Checks the left
        || otherObject->topLeft.y >= bottomRight.y //Checks the bottom
        || otherObject->bottomRight.y <= topLeft.y) //Checks the top
        return false;

    return true;
}

bool CollisionObject::checkForIntersection(const Vector& topLeftOther, const Vector& bottomRightOther)
{
    updatePosition();

    if (topLeftOther.x >= bottomRight.x //Checks the right
        || bottomRightOther.x <= topLeft.x //Checks the left
        || topLeftOther.y >= bottomRight.y //Checks the bottom
        || bottomRightOther.y <= topLeft.y) //Checks the top
        return false;

    return true;
}

bool CollisionObject::collisionResponse(CollisionObject* otherObject)
{
    return true;
}

void CollisionObject::createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter)
{
    height = shapeHeight;
    width = shapeWidth;

    center = shapeCenter;

    pixelBorder.resize(static_cast<int>(shapeHeight * 2 + shapeWidth * 2 - 4));
}

void CollisionObject::updatePosition()
{
    topLeft.x = center->x - width / 2;
    topLeft.y = center->y - height / 2;
    bottomRight.x = center->x + width / 2;
    bottomRight.y = center->y + height / 2;
}

void CollisionObject::updatePixelBorder()
{
    auto measure = new MeasurePerformance;
    measure->start();
    int heightCounter = 1;

    for (size_t pixel = 0; pixel < pixelBorder.size(); ++pixel)
    {
        if (pixel < width)
        {
            pixelBorder[pixel].y = center->y - height / 2;
            pixelBorder[pixel].x = center->x - width / 2 + pixel;
        }
        else if (heightCounter < height)
        {
            pixelBorder[pixel].y = center->y - height / 2 + heightCounter;
            if (heightCounter % 2)
            {
                pixelBorder[pixel].x = center->x - width / 2;
            }
            else
            {
                pixelBorder[pixel].x = center->x + width / 2;
            }
            heightCounter++;
        } else
        {
            pixelBorder[pixel].y = center->y + height / 2;
            pixelBorder[pixel].x = center->x - width / 2 + pixel;
        }
    }
    measure->end("Time for update: ");
}

void CollisionObject::calculateCollisionNormal(CollisionObject* otherObject)
{
}
