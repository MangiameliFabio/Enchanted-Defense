#include <chrono>
#include <cstdio>
#include <SDL.h>

#include "Singelton.h"
#include "Core/Patterns/Subject.h"
#include "Core/Renderer.h"
#include "Core/GameClock.h"
#include "../Game/WorldMAnager.h"
#include "../Game/Player/InputManager.h"
#include "Core/MeasurePerformance.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    const auto timer = new MeasurePerformance;
    if (MEASURE_PERFORMANCE) { timer->start(); }
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
    SINGLETON->addObserver(PLAYER);

    //Event handler
    SDL_Event e;
    if (MEASURE_PERFORMANCE) { timer->end("Time for initialization: "); }

    while (!SINGLETON->gQuit)
    {
        if (MEASURE_PERFORMANCE) { printf("--------------------------------------------------- \n"); }

        if (MEASURE_PERFORMANCE) { timer->start(); }
        gameClock->startTick();

        //Clear everything in delete queue
        SINGLETON->gQueueForDelete.clear();
        SINGLETON->sizeQueueForDelete = 0;

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
        if (MEASURE_PERFORMANCE) { timer->end("Start main loop and handle input: "); }

        //Update alle Objects
        if (MEASURE_PERFORMANCE) { timer->start(); }
        for (int object = 0; object < SINGLETON->sizeObjectList; ++object)
        {
            const auto measureObjects = new MeasurePerformance;
            if (MEASURE_PERFORMANCE)
            {
                measureObjects->start();
            }
            if (SINGLETON->gObjectList[object]->shouldUpdate)
            {
                SINGLETON->gObjectList[object]->update();
            }
            if (MEASURE_PERFORMANCE)
            {
                measureObjects->end("  " + std::to_string(object) + ". " + SINGLETON->gObjectList[object]->name + ":");
            }
        }
        if (MEASURE_PERFORMANCE) { timer->end("All objects updated: "); }

        //Delete Objects waiting in queue
        if (MEASURE_PERFORMANCE) { timer->start(); }
        for (int object = 0; object < SINGLETON->sizeQueueForDelete; ++object)
        {
            delete SINGLETON->gQueueForDelete[object];
        }
        if (MEASURE_PERFORMANCE) { timer->end("handle queue for delete: "); }

        //Render Scene
        if (MEASURE_PERFORMANCE) { timer->start(); }
        SINGLETON->gRenderer->renderUpdate();
        if (MEASURE_PERFORMANCE) { timer->end("render loop finished: "); }

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    SINGLETON->gRenderer->close();
    gameClock->close();
    inputManager->close();

    return 0;
}
