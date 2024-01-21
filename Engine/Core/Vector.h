#pragma once
#include <string>

struct Vector
{
    float x;
    float y;

    Vector() : x(0), y(0){}
    Vector(float x_, float y_) : x(x_), y(y_){}
    Vector(int x_, int y_) : x(static_cast<float>(x_)), y(static_cast<float>(y_)){}
    Vector(double x_, double y_) : x(static_cast<float>(x_)), y(static_cast<float>(y_)){}
    
    ~Vector(){}

    Vector& operator=(const Vector& v);
    Vector operator+(const Vector& v) const;
    void operator+=(const Vector& v);
    Vector operator-(const Vector& v) const;
    void operator-=(const Vector& v);
    Vector operator*(const float f) const;
    friend Vector operator*(const float f, const Vector& v);
    float operator*(const Vector& v) const;
    bool operator==(const Vector& v) const;

    float length() const;
    Vector normalize() const;
    void Zero();
    void print(const std::string& text = "") const;
    void round();

    static float dist(Vector& v1, Vector& v2);
    static bool compare(const Vector& v1, const Vector& v2, float tolerance);
    static Vector middleBetweenVec(const Vector& v1, const Vector& v2);
    static Vector rotate(const Vector& v, float angle);
};
