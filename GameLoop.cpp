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
        if (!renderer->loadMediaTexture("assets/textures/arrow.png"))
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
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_a:
                    SINGLETON->degrees -= 1;
                    break;

                case SDLK_d:
                    SINGLETON->degrees += 1;
                    break;

                case SDLK_q:
                    SINGLETON->flipType = SDL_FLIP_HORIZONTAL;
                    break;

                case SDLK_w:
                    SINGLETON->flipType = SDL_FLIP_NONE;
                    break;

                case SDLK_e:
                    SINGLETON->flipType = SDL_FLIP_VERTICAL;
                    break;
                }
            }
        }
        renderer->renderUpdate();
    }
    //Free resources and closeSDL
    renderer->close();
    return 0;
}
