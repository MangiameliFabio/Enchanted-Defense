#include <chrono>
#include <cstdio>
#include <SDL.h>

#include "Singelton.h"
#include "Core/Patterns/Subject.h"
#include "Core/Renderer.h"
#include "Core/GameClock.h"
#include "Core/Vector.h"
#include "../Game/WorldMAnager.h"
#include "../Game/Player/InputManager.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    const auto worldManager = new WorldManager;
    const auto gameClock = new GameClock;
    const auto inputManager = new InputManager;

    if (!SINGLETON->gRenderer->init())
    {
        printf("failed to initialize renderer \n");
    }
    SINGLETON->gRenderer = SINGLETON->gRenderer;

    //Initialize
    worldManager->createAssets();
    gameClock->init();
    SINGLETON->addObserver(SINGLETON->gPlayer);

    //Event handler
    SDL_Event e;

    while (!SINGLETON->gQuit)
    {
        gameClock->startTick();
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                SINGLETON->gQuit = true;
            }
        }
        //Get Current Input
        inputManager->handleInput();
        SINGLETON->notify(ALL_INPUTS_HANDLED);

        for (const auto object : SINGLETON->gObjectList)
        {
            if (object->shouldUpdate)
            {
                object->update();
            }
        }

        //Render Scene
        SINGLETON->gRenderer->renderUpdate();

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    SINGLETON->gRenderer->close();
    gameClock->close();
    inputManager->close();

    return 0;
}
