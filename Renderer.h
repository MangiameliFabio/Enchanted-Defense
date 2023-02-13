#pragma once
#include <SDL_render.h>
#include <SDL_video.h>

#include "Enums.h"
#include "LTexture.h"

class Renderer
{
public:    
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The images that correspond to a keypress
    SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

    //Current displayed image
    SDL_Surface* gCurrentSurface = NULL;

    //Scene textures
    LTexture gFooTexture;
    LTexture gBackgroundTexture;
    
    bool init();

    //Loads individual image
    SDL_Surface* loadSurface(std::string path);

    SDL_Texture* loadTexture(std::string path);

    //Loads media
    bool loadMediaIMG();

    bool loadMediaTexture();

    bool loadMediaColorKeying();

    bool loadNoMedia();

    //Frees media and shuts down SDL
    void close();
};
