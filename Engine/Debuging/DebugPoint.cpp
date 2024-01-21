#include "DebugPoint.h"

#include <SDL.h>

#include "..\EngineSingelton.h"

void DebugPoint::render()
{
    // Set the drawing color
    SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, color_.r, color_.g, color_.b, color_.a);

    // Draw a dot at pixel (x_, y_)
    SDL_RenderDrawPoint(ENGINE->gSDL_Renderer, x_, y_);

    DebugShape::render();
}
