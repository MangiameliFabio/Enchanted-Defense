#include <chrono>
#include <cstdio>
#include <SDL.h>

#include "GameClock.h"
#include "../Game/Player/InputManager.h"
#include "Renderer.h"
#include "Singelton.h"
#include "../Game/WorldMAnager.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    bool quit = false;

    const auto renderer = new Renderer;
    const auto worldManager = new WorldManager;
    const auto gameClock = new GameClock;
    const auto inputManager = new InputManager;
    Object object;

    if (!renderer->init())
    {
        printf("failed to initialize renderer \n");
    }

    worldManager->createAssets();
    gameClock->init();
    inputManager->init();

    //Event handler
    SDL_Event e;

    while (!quit)
    {
        gameClock->startTick();
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT || SINGLETON->gCurrentInput == QUIT)
            {
                quit = true;
            }
        }
        //Get Current Input
        inputManager->handleInput();

        for (const auto funcPtr : SINGLETON->updateFunctions)
        {
            funcPtr->update();
        }

        //Render Scene
        renderer->renderUpdate();

        //End of Tick
        gameClock->endTick();
    }

    renderer->close();
    gameClock->close();
    return 0;
}
