#include <chrono>
#include <cstdio>
#include <SDL.h>

#include "GameClock.h"
#include "../Game/Player/InputManager.h"
#include "Renderer.h"
#include "Singelton.h"
#include "Vector.h"
#include "../Game/WorldMAnager.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    const auto renderer = new Renderer;
    const auto worldManager = new WorldManager;
    const auto gameClock = new GameClock;
    const auto inputManager = new InputManager;
    const auto eventHandler = new Subject;

    Vector a(1, 1);
    Vector b(2, 2);

    Vector c = 3.f * a;

    printf("x = %f, y = %f", a.x, a.y);

    if (!renderer->init())
    {
        printf("failed to initialize renderer \n");
    }

    worldManager->createAssets();
    gameClock->init();
    eventHandler->addObserver(SINGLETON->Player);

    //Event handler
    SDL_Event e;

    while (!SINGLETON->quit)
    {
        gameClock->startTick();
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                SINGLETON->quit = true;
            }
        }
        //Get Current Input
        inputManager->handleInput();
        eventHandler->notify(ALL_INPUTS_HANDLED);

        for (const auto funcPtr : SINGLETON->updateFunctions)
        {
            funcPtr->update();
        }

        //Render Scene
        renderer->renderUpdate();

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    renderer->close();
    gameClock->close();
    inputManager->close();

    return 0;
}
