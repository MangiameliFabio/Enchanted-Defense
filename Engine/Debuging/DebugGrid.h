#pragma once
#include "DebugShape.h"

class DebugGrid : public DebugShape
{
    const int rows_ = 10;
    const int col_ = 10;
    const int cellSize_ = 10;
    const int x_ = 0;
    const int y_ = 0;

    Color color;

public:
    DebugGrid(const int rows, const int col, const int cellSize, const int x = 0, const int y = 0,
              Color color = Color(255, 255, 255, 255)) : rows_(rows),
                                                         col_(col), cellSize_(cellSize), x_(x), y_(y), color(color)
    {
    }

    ~DebugGrid() override = default;

    void render() override;
};
