#pragma once
#include <SDL.h>
#include <vector>

#include "../Debuging/DebugShape.h"

class Texture;

class Renderer
{
    //Textures to render
    std::vector<Texture*> textureContainer;
    std::vector<DebugShape*> debugContainer;

    int numTextures = 0;
    int numDebugShapes = 0;

public:
    bool init();

    void renderUpdate();
    void addTexture(Texture* texture);
    void addDebugShape(DebugShape* debugShape);
    void removeTexture(Texture* texture);
    void removeDebugShape(DebugShape* debugShape);

    std::vector<Texture*>& getTextures();

    //Frees media and shuts down SDL
    void close();

    //The window we'll be rendering to
    SDL_Window* gWindow = nullptr;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = nullptr;
};
