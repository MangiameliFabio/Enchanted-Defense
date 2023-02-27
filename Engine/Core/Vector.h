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
    Vector operator+(const Vector& v);
    void operator+=(const Vector& v);
    Vector operator-(const Vector& v);
    void operator-=(const Vector& v);
    Vector operator*(const float f) const;
    friend Vector operator*(const float f, Vector v);
    float operator*(Vector& v);
    bool operator==(const Vector& v);

    float length();
    Vector normalize();
    void Zero();
    void print(std::string text = "");
    void round();

    static float dist(Vector& v1, Vector& v2);
    static bool compare(Vector& v1, Vector& v2, float tolerance);
    static Vector middleBetweenVec(Vector& v1, Vector& v2);
    static Vector rotate(Vector& v, float angle);
};
