#include "Vector.h"

#include <cmath>
#include "Helper.h"

Vector& Vector::operator=(const Vector& v)
{
    if (this == &v) return *this;
    x = v.x;
    y = v.y;
    return *this;
}

Vector Vector::operator+(const Vector& v) const
{
    return {x + v.x, y + v.y};
}

void Vector::operator+=(const Vector& v)
{
    x += v.x;
    y += v.y;
}

Vector Vector::operator-(const Vector& v) const
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

Vector operator*(const float f, const Vector& v)
{
    return {v.x * f, v.y * f};
}

float Vector::operator*(const Vector& v) const
{
    return x * v.x + y * v.x;
}

bool Vector::operator==(const Vector& v) const
{
    return Helper::epsilonComparison(v.x, x) && Helper::epsilonComparison(v.y, y);
}

float Vector::length() const
{
    return (abs(std::sqrt(x * x + y * y)));
}

Vector Vector::normalize() const
{
    const float vLength = length();
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

void Vector::print(const std::string& text) const
{
    printf("%sx: %.0f, y: %.1f \n", text.c_str(), x, y);
}

void Vector::round()
{
    x = roundf(x);
    y = roundf(y);
}

float Vector::dist(Vector& v1, Vector& v2)
{
    return (v1 - v2).length();
}

bool Vector::compare(const Vector& v1, const Vector& v2, const float tolerance)
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

Vector Vector::middleBetweenVec(const Vector& v1, const Vector& v2)
{
    return {(v1.x + v2.x) / 2, (v1.y + v2.y) / 2};
}

//     ( cos α | -sin α) (vx) 
//     ( sin α | cos α ) (vy)
Vector Vector::rotate(const Vector& v, const float angle)
{
    const double radian = Helper::degreeToRadian(angle);

    const double x = cos(radian) * static_cast<double>(v.x) + -sin(radian) * static_cast<double>(v.y);
    const double y = sin(radian) * static_cast<double>(v.x) + cos(radian) * static_cast<double>(v.y);

    return {x, y};
}
