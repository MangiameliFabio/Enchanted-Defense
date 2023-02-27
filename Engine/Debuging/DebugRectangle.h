#pragma once
#include "DebugShape.h"

class DebugRectangle : public DebugShape
{
    const int x_ = 0;
    const int y_ = 0;
    const int width_ = 0;
    const int height_ = 0;

    Color color;

public:
    DebugRectangle(const int x, const int y, const int width, const int height,
                   Color color = Color(255, 255, 255, 255)) : x_(x),
                                                              y_(y), width_(width), height_(height), color(color)
    {
    }

    ~DebugRectangle() override = default;

    void render() override;
};
