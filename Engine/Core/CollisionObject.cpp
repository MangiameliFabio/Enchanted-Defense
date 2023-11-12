#include "CollisionObject.h"

#include "Object.h"
#include "../Debuging/DebugPoint.h"

CollisionObject::CollisionObject()
{
}

void CollisionObject::init(Object* parent)
{
    mParent = parent;
}

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

void CollisionObject::createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter)
{
    mHeight = shapeHeight;
    mWidth = shapeWidth;

    mCenter = shapeCenter;

    mPixelBorder.resize(static_cast<int>(shapeHeight * 2 + shapeWidth * 2 - 4));
}

void CollisionObject::updatePosition()
{
    topLeft.x = mCenter->x - mWidth / 2;
    topLeft.y = mCenter->y - mHeight / 2;
    bottomRight.x = mCenter->x + mWidth / 2;
    bottomRight.y = mCenter->y + mHeight / 2;
}

//Update pixels used for collision response
void CollisionObject::updatePixelBorder()
{
    int heightCounter = 0;
    int widthCounter = 0;

    for (size_t pixel = 0; pixel < mPixelBorder.size(); ++pixel)
    {
        if (pixel < mWidth - 1)
        {
            mPixelBorder[pixel].position.y = mCenter->y - mHeight / 2;
            mPixelBorder[pixel].position.x = mCenter->x - mWidth / 2 + pixel;
        }
        else if (heightCounter < mHeight - 1)
        {
            mPixelBorder[pixel].position.y = mCenter->y - mHeight / 2 + heightCounter;
            mPixelBorder[pixel].position.x = mCenter->x - mWidth / 2;
            heightCounter++;
        }
        else if (heightCounter < (mHeight - 1) * 2)
        {
            mPixelBorder[pixel].position.y = mCenter->y - mHeight / 2 + heightCounter - (mHeight - 1);
            mPixelBorder[pixel].position.x = mCenter->x + mWidth / 2 - 1;
            heightCounter++;
        }
        else
        {
            mPixelBorder[pixel].position.y = mCenter->y + mHeight / 2 - 1;
            mPixelBorder[pixel].position.x = mCenter->x - mWidth / 2 + widthCounter;
            widthCounter++;
        }
    }
}

void CollisionObject::close()
{
    mCenter = nullptr;
    mPixelBorder.clear();
    mParent = nullptr;
}

bool CollisionObject::calculateCollisionPoint(CollisionObject* otherObject, RaycastHit& hit)
{
    std::vector<Vector*> collisions;

    updatePixelBorder();
    otherObject->updatePixelBorder();

    for (size_t i = 0; i < mPixelBorder.size(); ++i)
    {
        for (size_t j = 0; j < otherObject->mPixelBorder.size(); ++j)
        {
            if (Vector::compare(mPixelBorder[i].position, otherObject->mPixelBorder[j].position, 0.5f))
            {
                collisions.push_back(&mPixelBorder[i].position);
                break;
            }
        }
    }

    if (!collisions.empty() && collisions.size() >= 2)
    {
        Vector relVelocity = mParent->velocity - otherObject->mParent->velocity;
        Vector relVelocityNorm = relVelocity.normalize();

        Vector origin = Vector::middleBetweenVec(*collisions[0], *collisions[collisions.size() - 1]);
        hit = Raycast(origin, relVelocityNorm, mPixelBorder);

        return true;
    }

    return false;
}

void CollisionObject::collisionResponse(CollisionObject* otherObject)
{
    //Calculate collision normal and relative velocity
    Vector collNormal = (*mCenter - *otherObject->mCenter).normalize();
    Vector relativeVel = mParent->velocity - otherObject->mParent->velocity;

    //Calculate change of momentum
    float restitution = 0.f;
    float impulse = -(1 + restitution) * relativeVel * collNormal;
    // ((1.f / 50.f) + (1.f / 50.f))

    //Impuls is sometimes really big so clamp it to 50
    if (impulse > 50)
    {
        impulse = 50;
    }

    //Apply impulse on velocities
    mParent->velocity += impulse * collNormal;
    otherObject->mParent->velocity -= impulse * collNormal;
}
