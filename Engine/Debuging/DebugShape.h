#pragma once

struct Color
{
    Color(const int r, const int g, const int b, const int a): r(r), g(g), b(b), a(a)
    {
    }

    int r = 255;
    int g = 255;
    int b = 255;
    int a = 255;
};

class DebugShape
{
public:
    DebugShape();
    virtual ~DebugShape();

    virtual void render();

    int zIndex = 0;

    bool markForDelete = true;
    bool persistent = true;
};
