#pragma once
#include <vector>

#include "Vector.h"
#include <complex>

struct Collider
{
    Vector position;
    float radius = 1.f;
};

struct RaycastHit
{
    Collider collider;

    Vector point;
    Vector normal;

    float distance;
};

static RaycastHit Raycast(Vector origin, Vector direction, std::vector<Collider>& colliders)
{
    RaycastHit hit;
    hit.distance = std::numeric_limits<float>::max();

    for (Collider& collider : colliders)
    {
        // Calculate the vector from the ray origin to the collider center
        Vector toCollider = collider.position - origin;

        // Project the vector onto the ray direction to get the distance along the ray
        float distance = toCollider.x * direction.x + toCollider.y * direction.y;

        // If the distance is negative, the collider is behind the ray origin, so skip it
        if (distance < 0)
        {
            continue;
        }

        // Calculate the closest point on the ray to the collider center
        Vector closestPoint = origin + distance * direction;

        // Calculate the distance between the closest point and the collider center
        float distToCollider = std::sqrt(
            std::pow(closestPoint.x - collider.position.x, 2) + std::pow(closestPoint.y - collider.position.y, 2));

        // If the distance is less than the collider radius, there is an intersection
        if (distToCollider <= collider.radius)
        {
            // If this is the closest intersection so far, update the hit
            if (distance < hit.distance)
            {
                hit.normal = (origin - closestPoint).normalize();
                hit.collider = collider;
                hit.point = closestPoint;
                hit.distance = distance;
            }
        }
    }

    return hit;
}
