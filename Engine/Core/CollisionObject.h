#pragma once

#include <vector>

#include "Raycast.h"
#include "Vector.h"

class Object;
struct AStarNode;

class CollisionObject
{
    Vector* center = nullptr;
    std::vector<Collider> pixelBorder;
    Object* parent;

    float width = 0;
    float height = 0;

public:
    CollisionObject(Object* parent) : parent(parent)
    {
    }

    ~CollisionObject() = default;

    bool checkForIntersection(CollisionObject* otherObject);
    bool checkForIntersection(const Vector& topLeft, const Vector& bottomRight);

    bool calculateCollisionPoint(CollisionObject* otherObject, RaycastHit& hit);
    void collisionResponse(CollisionObject* otherObject);

    void createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter);
    void updatePosition();
    void updatePixelBorder();


    Vector topLeft;
    Vector bottomRight;
};
