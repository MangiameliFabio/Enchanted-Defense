#include "DebugRectangle.h"

#include <SDL.h>

#include "..\EngineSingelton.h"

void DebugRectangle::render()
{
    DebugShape::render();

    // Set the color to red
    SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, color.r, color.g, color.b, color.a);

    // Create a rectangle to fill
    SDL_Rect rect = {x_, y_, width_, height_};

    // Fill the rectangle with the current color
    SDL_RenderFillRect(ENGINE->gSDL_Renderer, &rect);
}
