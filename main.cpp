#include <cstdio>
#include <SDL.h>

#include "Renderer.h"
#include "Singelton.h"
#include "WorldMAnager.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    bool quit = false;

    const auto renderer = new Renderer;
    const auto worldManager = new WorldManager;

    if (!renderer->init())
    {
        printf("failed to initialize renderer");
    }

    worldManager->createAssets();

    //Event handler
    SDL_Event e;

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

        //Render Scene
        renderer->renderUpdate();
    }

    renderer->close();
    return 0;
}
