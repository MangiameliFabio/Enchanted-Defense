#pragma once
#include "DebugShape.h"
#include "../Core/Vector.h"

class DebugLine : public DebugShape
{
    Vector start_;
    Vector end_;
    Color color_;

public:
    DebugLine(Vector start, Vector end, Color color = Color(255, 255, 255, 255)) : start_(start), end_(end), color_(color){}
    ~DebugLine() override = default;

    void render() override;
};
