﻿#include <chrono>
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>

#include "EngineSingelton.h"
#include "Core/Patterns/Subject.h"
#include "Core/Renderer.h"
#include "Core/GameClock.h"
#include "../Game/WorldMAnager.h"
#include "Core/MeasurePerformance.h"

EngineSingleton* EngineSingleton::instance = nullptr;

int main(int argc, char* args[])
{
    //Create timer for performance measurement;
    const auto meassureMain = new MeasurePerformance;
    const auto measureObjects = new MeasurePerformance;
    if (MEASURE_PERFORMANCE) { meassureMain->start(); }

    //Initialize
    if (!ENGINE->gRenderer->init())
    {
        printf("failed to initialize renderer \n");
    }
    
    const auto worldManager = new WorldManager;
    worldManager->init();
    const auto gameClock = new GameClock;
    gameClock->init();
    
    //Event handler
    SDL_Event e;
    if (MEASURE_PERFORMANCE) { meassureMain->end("Time for initialization: "); }

    while (!ENGINE->gQuit)
    {
        if (MEASURE_PERFORMANCE) { printf("--------------------------------------------------- \n"); }

        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
        gameClock->startTick();

        //Clear everything in delete queue
        ENGINE->gQueueForDelete.clear();
        ENGINE->sizeQueueForDelete = 0;

        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                ENGINE->gQuit = true;
            }
        }

        if (MEASURE_PERFORMANCE) { meassureMain->end("Start main loop and handle input: "); }

        ENGINE->notify(HANDLE_INPUT);

        //Update alle Objects
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }

        for (int object = 0; object < ENGINE->sizeObjectList; ++object)
        {
            if (MEASURE_PERFORMANCE)
            {
                measureObjects->start();
            }
            if (ENGINE->gObjectList[object]->shouldUpdate)
            {
                ENGINE->gObjectList[object]->update();
            }
            if (MEASURE_PERFORMANCE)
            {
                measureObjects->end("  " + std::to_string(object) + ". " + ENGINE->gObjectList[object]->name + ":");
            }
        }
        if (MEASURE_PERFORMANCE) { meassureMain->end("All objects updated: "); }

        //Delete Objects waiting in queue
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
        for (int object = 0; object < ENGINE->sizeQueueForDelete; ++object)
        {
            delete ENGINE->gQueueForDelete[object];
        }
        if (MEASURE_PERFORMANCE) { meassureMain->end("handle queue for delete: "); }

        //Render Scene
        if (MEASURE_PERFORMANCE) { meassureMain->start(); }
        ENGINE->gRenderer->renderUpdate();
        if (MEASURE_PERFORMANCE) { meassureMain->end("render loop finished: "); }

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    ENGINE->gRenderer->close();
    gameClock->close();

    return 0;
}
