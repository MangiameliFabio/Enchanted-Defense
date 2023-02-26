#pragma once

#include <vector>

#include "Vector.h"

struct AStarNode;

class CollisionObject
{
    Vector* center = nullptr;
    std::vector<Vector> pixelBorder;

    float width = 0;
    float height = 0;

public:
    CollisionObject()
    {
    }

    ~CollisionObject()
    {
    }

    bool checkForIntersection(CollisionObject* otherObject);
    bool checkForIntersection(const Vector& topLeft, const Vector& bottomRight);
    bool collisionResponse(CollisionObject* otherObject);

    void createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter);
    void updatePosition();
    void updatePixelBorder();

    void calculateCollisionNormal(CollisionObject* otherObject);

    Vector topLeft;
    Vector bottomRight;
};
