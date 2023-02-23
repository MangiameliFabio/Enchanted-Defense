#pragma once
#include <SDL_render.h>
#include <vector>

#include "Texture.h"

class Renderer
{
    //Textures to render
    std::vector<Texture*> textureContainer;
    int numTextures = 0;

public:
    bool init();

    void renderUpdate();
    void addTexture(Texture* texture);
    void removeTexture(Texture* texture);

    //Frees media and shuts down SDL
    void close();

    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = nullptr;
};
