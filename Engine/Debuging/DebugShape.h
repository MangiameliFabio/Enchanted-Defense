#pragma once
#include <SDL_stdinc.h>

struct Color
{
    Color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a): r(r), g(g), b(b), a(a)
    {
    }

    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;
    Uint8 a = 255;
};

class DebugShape
{
public:
    DebugShape();
    virtual ~DebugShape();

    virtual void render();

    int zIndex = 0;

    bool persistent = true;
};
