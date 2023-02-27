#pragma once
#include "DebugShape.h"

class DebugPoint : public DebugShape
{
    int x_;
    int y_;

    Color color_;

public:
    DebugPoint(int x, int y, Color color = Color(255, 255, 255, 255)) : x_(x), y_(y), color_(color){}
    ~DebugPoint() override {}
    
    void render() override;
};
