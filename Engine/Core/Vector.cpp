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
        return {};
    }
    const Vector normalized = *this;
    return normalized * (1.f / length());
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

void Vector::round()
{
    static_cast<int>(x + 0.5f);
    static_cast<int>(y + 0.5f);
}

float Vector::dist(Vector& v1, Vector& v2)
{
    return (v1 - v2).length();
}

bool Vector::compare(Vector& v1, Vector& v2, float tolerance)
{
    if (!Helper::epsilonComparison(v1.x, v2.x, tolerance))
    {
        return false;
    }
    if (!Helper::epsilonComparison(v1.y, v2.y, tolerance))
    {
        return false;
    }
    return true;
}

Vector Vector::middleBetweenVec(Vector& v1, Vector& v2)
{
    return Vector((v1.x + v2.x) / 2, (v1.y + v2.y) / 2);
}

//     ( cos α | -sin α) (vx) 
//     ( sin α | cos α ) (vy)
Vector Vector::rotate(Vector& v, float angle)
{
    double radian = DEGREE_TO_R(angle);

    double x = cos(radian) * static_cast<double>(v.x) + -sin(radian) * static_cast<double>(v.y);
    double y = sin(radian) * static_cast<double>(v.x) + cos(radian) * static_cast<double>(v.y);

    return Vector(x, y);
}
