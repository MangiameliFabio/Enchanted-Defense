// /*This source code copyrighted by Lazy Foo' Productions (2004-2022)
// and may not be redistributed without written permission.*/
//
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Renderer.h"

int main(int argc, char* args[])
{
    const auto renderer = new Renderer;
    //Start up SDL and create window
    if (!renderer->init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!renderer->loadMediaTexture())
        {
            printf("Failed to load media!\n");
        }
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Set default current surface
    renderer->gCurrentSurface = renderer->gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        //Top left corner viewport
        SDL_Rect topLeftViewport;
        topLeftViewport.x = 0;
        topLeftViewport.y = 0;
        topLeftViewport.w = renderer->SCREEN_WIDTH / 2;
        topLeftViewport.h = renderer->SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport( renderer->gRenderer, &topLeftViewport );
                
        //Render texture to screen
        SDL_RenderCopy( renderer->gRenderer, renderer->gTexture, NULL, NULL );

        //Top right viewport
        SDL_Rect topRightViewport;
        topRightViewport.x = renderer->SCREEN_WIDTH / 2;
        topRightViewport.y = 0;
        topRightViewport.w = renderer->SCREEN_WIDTH / 2;
        topRightViewport.h = renderer->SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport( renderer->gRenderer, &topRightViewport );
                
        //Render texture to screen
        SDL_RenderCopy( renderer->gRenderer, renderer->gTexture, NULL, NULL );

        //Bottom viewport
        SDL_Rect bottomViewport;
        bottomViewport.x = 0;
        bottomViewport.y = renderer->SCREEN_HEIGHT / 2;
        bottomViewport.w = renderer->SCREEN_WIDTH;
        bottomViewport.h = renderer->SCREEN_HEIGHT / 2;
        SDL_RenderSetViewport( renderer->gRenderer, &bottomViewport );
                
        //Render texture to screen
        SDL_RenderCopy( renderer->gRenderer, renderer->gTexture, NULL, NULL );

        //Update screen
        SDL_RenderPresent( renderer->gRenderer );
    }

    //Free resources and closeSDL
    renderer->close();

    return 0;
}
