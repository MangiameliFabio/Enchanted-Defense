#include "CollisionObject.h"

#include <algorithm>

#include "MeasurePerformance.h"
#include "../Pathfinding.h"
#include "../Debuging/DebugPoint.h"
#include "../Debuging/DebugRectangle.h"

bool CollisionObject::checkForIntersection(CollisionObject* otherObject)
{
    updatePosition();
    otherObject->updatePosition();

    // auto rect = new DebugRectangle(10, 10, topLeft.x, topLeft.y, Color(255, 0, 0, 255));
    // rect->persistent = false;
    //
    // auto rect2 = new DebugRectangle(10, 10, bottomRight.x, bottomRight.y, Color(255, 0, 0, 255));
    // rect2->persistent = false;

    if (otherObject->topLeft.x >= bottomRight.x //Checks the right
        || otherObject->bottomRight.x <= topLeft.x //Checks the left
        || otherObject->topLeft.y >= bottomRight.y //Checks the bottom
        || otherObject->bottomRight.y <= topLeft.y) //Checks the top
        return false;

    calculateCollisionNormal(otherObject);

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

//Update pixels used for collision response
void CollisionObject::updatePixelBorder()
{
    int heightCounter = 0;
    int widthCounter = 0;

    for (size_t pixel = 0; pixel < pixelBorder.size(); ++pixel)
    {
        if (pixel < width - 1)
        {
            pixelBorder[pixel].position.y = center->y - height / 2;
            pixelBorder[pixel].position.x = center->x - width / 2 + pixel;
        }
        else if (heightCounter < height - 1)
        {
            pixelBorder[pixel].position.y = center->y - height / 2 + heightCounter;
            pixelBorder[pixel].position.x = center->x - width / 2;
            heightCounter++;
        }
        else if (heightCounter < (height - 1) * 2)
        {
            pixelBorder[pixel].position.y = center->y - height / 2 + heightCounter - (height - 1);
            pixelBorder[pixel].position.x = center->x + width / 2 - 1;
            heightCounter++;
        }
        else
        {
            pixelBorder[pixel].position.y = center->y + height / 2 - 1;
            pixelBorder[pixel].position.x = center->x - width / 2 + widthCounter;
            widthCounter++;
        }
        auto rect = new DebugPoint(pixelBorder[pixel].position.x, pixelBorder[pixel].position.y,
                                   Color(255, 255, 255, 255));
        rect->persistent = false;
    }
}

Vector CollisionObject::calculateCollisionNormal(CollisionObject* otherObject)
{
    auto measure = new MeasurePerformance;
    std::vector<Vector*> collisions;
    measure->start();

    updatePixelBorder();
    otherObject->updatePixelBorder();

    for (size_t i = 0; i < pixelBorder.size(); ++i)
    {
        for (size_t j = 0; j < otherObject->pixelBorder.size(); ++j)
        {
            if (Vector::compare(pixelBorder[i].position, otherObject->pixelBorder[j].position, 1.f))
            {
                collisions.push_back(&pixelBorder[i].position);
                break;
            }
        }
    }

    if (!collisions.empty() && collisions.size() >= 2)
    {
        Vector relVelocity = parent->velocity - otherObject->parent->velocity;
        Vector relVelocityNorm = relVelocity.normalize();

        Vector origin = Vector::middleBetweenVec(*collisions[0], *collisions[collisions.size() - 1]);
        RaycastHit hit = Raycast(origin, relVelocityNorm, pixelBorder);

        auto rect = new DebugRectangle(hit.point.x, hit.point.y, 5, 5, Color(255, 0, 0, 255));
        rect->persistent = false;
    }
    measure->end("Time for update: ");

    return {};
}
