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
#include "Debuging/DebugLine.h"

Singleton* Singleton::instance = nullptr;

int main(int argc, char* args[])
{
    //Create timer for performance measurement;
    const auto meassureMain = new MeasurePerformance;
    const auto measureObjects = new MeasurePerformance;
    if (MEASURE_PERFORMANCE) { meassureMain->start(); }

    //Initialize
    if (!SINGLETON->gRenderer->init())
    {
        printf("failed to initialize renderer \n");
    }
    const auto worldManager = new WorldManager;
    worldManager->init();
    const auto gameClock = new GameClock;
    gameClock->init();
    const auto inputManager = new InputManager;
    SINGLETON->addObserver(PLAYER);

    //Event handler
    SDL_Event e;
    if (MEASURE_PERFORMANCE) { meassureMain->end("Time for initialization: "); }

    while (!SINGLETON->gQuit)
    {
        if (MEASURE_PERFORMANCE) { printf("--------------------------------------------------- \n"); }

        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
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
        if (MEASURE_PERFORMANCE) { meassureMain->end("Start main loop and handle input: "); }

        //Update alle Objects
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }

        for (int object = 0; object < SINGLETON->sizeObjectList; ++object)
        {
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
        if (MEASURE_PERFORMANCE) { meassureMain->end("All objects updated: "); }

        //Delete Objects waiting in queue
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
        for (int object = 0; object < SINGLETON->sizeQueueForDelete; ++object)
        {
            delete SINGLETON->gQueueForDelete[object];
        }
        if (MEASURE_PERFORMANCE) { meassureMain->end("handle queue for delete: "); }

        //Render Scene
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
        SINGLETON->gRenderer->renderUpdate();
        if (MEASURE_PERFORMANCE) { meassureMain->end("render loop finished: "); }

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    SINGLETON->gRenderer->close();
    gameClock->close();
    inputManager->close();

    return 0;
}
