#include "Vector.h"

#include <cmath>
#include <cstdio>

Vector& Vector::operator=(const Vector& v)
{
    if (this == &v) return *this;
    x = v.x;
    y = v.y;
    return *this;
}

Vector Vector::operator+(const Vector& v)
{
    x = x + v.x;
    y = y + v.y;
    return *this;
}

Vector& Vector::operator+=(const Vector& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vector Vector::operator-(const Vector& v)
{
    x = x - v.x;
    y = y - v.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vector Vector::operator*(const float f)
{
    x = x * f;
    y = y * f;

    return *this;
}

Vector operator*(const float f, Vector v)
{
    v.x = v.x * f;
    v.y = v.y * f;

    return v;
}

float Vector::length()
{
    return abs(sqrt(x * x + y * y));
}

Vector Vector::normalize()
{
    float vLength = length();
    if (vLength == 0.f)
    {
        printf("Can't normalize Vector with length 0 \n");
        return *this;
    }
    return *this * (1.f / length());
}

void Vector::Zero()
{
    x = 0;
    y = 0;
}
