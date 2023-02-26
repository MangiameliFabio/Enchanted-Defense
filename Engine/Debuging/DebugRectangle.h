#pragma once
#include "DebugShape.h"

class DebugRectangle : public DebugShape
{
    const int width_ = 0;
    const int height_ = 0;
    const int x_ = 0;
    const int y_ = 0;

    Color color;

public:
    DebugRectangle(const int width, const int height, const int x, const int y,
                   Color color = Color(255, 255, 255, 255)) : width_(width),
                                                              height_(height), x_(x), y_(y), color(color)
    {
    }

    ~DebugRectangle() override = default;

    void render() override;
};
