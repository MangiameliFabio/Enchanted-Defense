#pragma once

#include <vector>

#include "Raycast.h"
#include "Vector.h"

class Object;
struct AStarNode;

class CollisionObject
{
    std::vector<Collider> mPixelBorder;

    Object* mParent = nullptr;
    Vector* mCenter = nullptr;

    float mWidth = 0;
    float mHeight = 0;

public:
    CollisionObject();
    ~CollisionObject() = default;

    void init(Object* parent);

    void drawCollisionShape(bool persistent = false);

    bool checkForIntersection(CollisionObject* otherObject);
    bool checkForIntersection(const Vector& topLeft, const Vector& bottomRight);

    bool checkIfPointInCollision(const Vector& point) const;

    bool calculateCollisionPoint(CollisionObject* otherObject, RaycastHit& hit);
    void collisionResponse(CollisionObject* otherObject);

    void createCollisionShape(float shapeHeight, float shapeWidth, Vector* shapeCenter);
    void updatePosition();
    void updatePixelBorder();

    void close();

    Vector topLeft;
    Vector bottomRight;
};
