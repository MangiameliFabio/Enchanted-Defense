#include "DebugLine.h"

#include <SDL_render.h>

#include "../Singelton.h"

void DebugLine::render()
{
    // Set the color to draw with
    SDL_SetRenderDrawColor(SINGLETON->gSDL_Renderer, color_.r, color_.g, color_.b, color_.a);

    SDL_RenderDrawLine(SINGLETON->gSDL_Renderer, start_.x, start_.y, end_.x, end_.y);

    DebugShape::render();
}
