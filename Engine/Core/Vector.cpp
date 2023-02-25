#include "Vector.h"

#include <cmath>
#include <cstdio>

#include "Helper.h"

Vector& Vector::operator=(const Vector& v)
{
    if (this == &v) return *this;
    x = v.x;
    y = v.y;
    return *this;
}

Vector Vector::operator+(const Vector& v)
{
    return {x + v.x, y + v.y};
}

void Vector::operator+=(const Vector& v)
{
    x += v.x;
    y += v.y;
}

Vector Vector::operator-(const Vector& v)
{
    return {x - v.x, y - v.y};
}

void Vector::operator-=(const Vector& v)
{
    x -= v.x;
    y -= v.y;
}

Vector Vector::operator*(const float f) const
{
    return {x * f, y * f};
}

Vector operator*(const float f, Vector v)
{
    return {v.x * f, v.y * f};
}

float Vector::operator*(Vector& v)
{
    return x * v.x + y * v.x;
}

bool Vector::operator==(const Vector& v)
{
    return F_EQUALS(v.x, x) && F_EQUALS(v.y, y);
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

void Vector::print(std::string text)
{
    printf("%sx: %.0f, y: %.1f \n", text.c_str(), x, y);
}

float Vector::dist(Vector& v1, Vector& v2)
{
    return (v1 - v2).length();
}
