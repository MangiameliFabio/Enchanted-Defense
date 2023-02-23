#pragma once

struct Vector
{
    float x;
    float y;

    Vector() : x(0), y(0){}
    Vector(float x_, float y_) : x(x_), y(y_){}
    ~Vector(){}

    Vector& operator=(const Vector& v);
    Vector operator+(const Vector& v);
    Vector& operator+=(const Vector& v);
    Vector operator-(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector operator*(const float f);
    friend Vector operator*(const float f, Vector v);

    float length();
    Vector normalize();
    void Zero();
};
