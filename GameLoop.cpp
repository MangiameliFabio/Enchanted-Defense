// /*This source code copyrighted by Lazy Foo' Productions (2004-2022)
// and may not be redistributed without written permission.*/
//
//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>

#include "Renderer.h"
#include "Singelton.h"

Singleton* Singleton::instance = NULL;

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
        if (!renderer->loadMediaColorKeying())
        {
            printf("Failed to load media!\n");
        }
    }
    
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

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
        //Clear screen
        SDL_SetRenderDrawColor( SINGLETON->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( SINGLETON->gRenderer );

        //Render background texture to screen
        renderer->gBackgroundTexture.render( 0, 0 );

        //Render Foo' to the screen
        renderer->gFooTexture.render( 240, 190 );

        //Update screen
        SDL_RenderPresent( SINGLETON->gRenderer );
    }

    //Free resources and closeSDL
    renderer->close();

    return 0;
}
