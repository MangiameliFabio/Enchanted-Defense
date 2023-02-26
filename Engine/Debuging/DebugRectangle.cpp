#include "DebugRectangle.h"

#include <SDL_render.h>

#include "../Singelton.h"

void DebugRectangle::render()
{
    // Set the color to red
    SDL_SetRenderDrawColor(SINGLETON->gSDL_Renderer, color.r, color.g, color.b, color.a);

    // Create a rectangle to fill
    SDL_Rect rect = {x_, y_, width_, height_};

    // Fill the rectangle with the current color
    SDL_RenderFillRect(SINGLETON->gSDL_Renderer, &rect);

    DebugShape::render();
}
