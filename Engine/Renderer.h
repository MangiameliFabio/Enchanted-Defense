#pragma once
#include <SDL_render.h>

class Renderer
{
public:
    bool init();

    void renderUpdate();

    //Frees media and shuts down SDL
    void close();

    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = nullptr;
};
