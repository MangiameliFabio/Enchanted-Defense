#include "Renderer.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Singelton.h"

bool Renderer::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            SINGLETON->gRenderer =
                SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (SINGLETON->gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(SINGLETON->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

void Renderer::renderUpdate()
{
    //Clear screen
    SDL_SetRenderDrawColor(SINGLETON->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(SINGLETON->gRenderer);

    //Render arrow
    gCustomTexture.render((SCREEN_WIDTH - gCustomTexture.getWidth()) / 2, (SCREEN_HEIGHT - gCustomTexture.getHeight()) / 2,
                         NULL, SINGLETON->degrees, NULL, SINGLETON->flipType);

    //Update screen
    SDL_RenderPresent(SINGLETON->gRenderer);
}

SDL_Surface* Renderer::loadSurface(std::string path)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

SDL_Texture* Renderer::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(SINGLETON->gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool Renderer::loadMediaIMG()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("assets/images/press.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf("Failed to load default image!\n");
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("assets/images/up.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
    {
        printf("Failed to load up image!\n");
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("assets/images/down.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        printf("Failed to load down image!\n");
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("assets/images/left.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        printf("Failed to load left image!\n");
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("assets/images/right.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        printf("Failed to load right image!\n");
        success = false;
    }

    return success;
}

bool Renderer::loadMediaTexture(std::string path)
{
    //Loading success flag
    bool success = true;

    //Load texture
    if (!gCustomTexture.loadFromFile(path))
    {
        printf("Failed to load texture image!\n");
        success = false;
    }

    return success;
}

bool Renderer::loadMediaColorKeying()
{
    //Loading success flag
    bool success = true;

    //Load Foo' texture
    if (!gFooTexture.loadFromFile("assets/textures/foo.png"))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }

    //Load background texture
    if (!gBackgroundTexture.loadFromFile("assets/textures/background.png"))
    {
        printf("Failed to load background texture image!\n");
        success = false;
    }

    return success;
}

bool Renderer::loadMediaSprites()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!gSpriteSheetTexture.loadFromFile("assets/textures/sprites.png"))
    {
        printf("Failed to load sprite sheet texture!\n");
        success = false;
    }
    else
    {
        //Set top left sprite
        gSpriteClips[0].x = 0;
        gSpriteClips[0].y = 0;
        gSpriteClips[0].w = 100;
        gSpriteClips[0].h = 100;

        //Set top right sprite
        gSpriteClips[1].x = 100;
        gSpriteClips[1].y = 0;
        gSpriteClips[1].w = 100;
        gSpriteClips[1].h = 100;

        //Set bottom left sprite
        gSpriteClips[2].x = 0;
        gSpriteClips[2].y = 100;
        gSpriteClips[2].w = 100;
        gSpriteClips[2].h = 100;

        //Set bottom right sprite
        gSpriteClips[3].x = 100;
        gSpriteClips[3].y = 100;
        gSpriteClips[3].w = 100;
        gSpriteClips[3].h = 100;
    }

    return success;
}

bool Renderer::loadMediaColors()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!gModulatedTexture.loadFromFile("assets/textures/full.png"))
    {
        printf("Failed to load sprite sheet texture!\n");
        success = false;
    }
    return success;
}

bool Renderer::loadMediaAlphaBlending()
{
    //Loading success flag
    bool success = true;

    //Load front alpha texture
    if (!gModulatedTexture.loadFromFile("assets/textures/fadeout.png"))
    {
        printf("Failed to load front texture!\n");
        success = false;
    }
    else
    {
        //Set standard alpha blending
        gModulatedTexture.setBlendMode(SDL_BLENDMODE_BLEND);
    }

    //Load background texture
    if (!gBackgroundTexture.loadFromFile("assets/textures/fadein.png"))
    {
        printf("Failed to load background texture!\n");
        success = false;
    }

    return success;
}

bool Renderer::loadMediaAnimation()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!gSpriteSheetTexture.loadFromFile("assets/textures/foo.png"))
    {
        printf("Failed to load walking animation texture!\n");
        success = false;
    }
    else
    {
        //Set sprite clips
        gSpriteClips[0].x = 0;
        gSpriteClips[0].y = 0;
        gSpriteClips[0].w = 64;
        gSpriteClips[0].h = 205;

        gSpriteClips[1].x = 64;
        gSpriteClips[1].y = 0;
        gSpriteClips[1].w = 64;
        gSpriteClips[1].h = 205;

        gSpriteClips[2].x = 128;
        gSpriteClips[2].y = 0;
        gSpriteClips[2].w = 64;
        gSpriteClips[2].h = 205;

        gSpriteClips[3].x = 192;
        gSpriteClips[3].y = 0;
        gSpriteClips[3].w = 64;
        gSpriteClips[3].h = 205;
    }

    return success;
}

bool Renderer::loadNoMedia()
{
    //Loading success flag
    bool success = true;

    //Nothing to load
    return success;
}

void Renderer::close()
{
    //Free loaded images
    gFooTexture.free();
    gBackgroundTexture.free();

    //Destroy window    
    SDL_DestroyRenderer(SINGLETON->gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SINGLETON->gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
