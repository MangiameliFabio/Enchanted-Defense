#include "DebugGrid.h"

#include <SDL.h>

#include "..\EngineSingelton.h"

void DebugGrid::render()
{
    // Set the color to draw with
    SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, color.r, color.g, color.b, color.a);

    // Draw horizontal lines
    for (int i = 0; i <= col_; i++)
    {
        SDL_RenderDrawLine(ENGINE->gSDL_Renderer, x_, i * cellSize_ + y_, x_ + rows_ * cellSize_,
                           i * cellSize_ + y_);
    }

    // Draw vertical lines
    for (int i = 0; i <= rows_; i++)
    {
        SDL_RenderDrawLine(ENGINE->gSDL_Renderer, i * cellSize_ + x_, y_, i * cellSize_ + x_,
                           y_ + rows_ * cellSize_);
    }
}
