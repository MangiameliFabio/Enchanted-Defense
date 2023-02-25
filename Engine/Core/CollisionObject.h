#pragma once

#include "Vector.h"

class CollisionObject
{
    Vector* center = nullptr;

    Vector topLeft;
    Vector bottomRight;

    float width = 0;
    float height = 0;

public:
    CollisionObject(){}
    ~CollisionObject(){}

    bool checkForIntersection(CollisionObject* otherObject);

    void createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter);

    void updatePosition();
};