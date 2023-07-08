#include "DebugLine.h"

#include <SDL_render.h>

#include "..\EngineSingelton.h"

void DebugLine::render()
{
    // Set the color to draw with
    SDL_SetRenderDrawColor(ENGINE->gSDL_Renderer, color_.r, color_.g, color_.b, color_.a);

    SDL_RenderDrawLine(ENGINE->gSDL_Renderer, start_.x, start_.y, end_.x, end_.y);

    DebugShape::render();
}
