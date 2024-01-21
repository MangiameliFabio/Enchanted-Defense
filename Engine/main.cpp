#include <chrono>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "EngineSingelton.h"
#include "Core/Patterns/Subject.h"
#include "Core/Renderer.h"
#include "Core/GameClock.h"
#include "../Game/GameManager.h"
#include "../Game/GameSingleton.h"
#include "Core/MeasurePerformance.h"
#include "Debuging/Log.h"
#include "UI/Button.h"

EngineSingleton* EngineSingleton::instance = nullptr;

int main(int argc, char* args[])
{
#if MEASURE_PERFORMANCE
    //Create timer for performance measurement;
    const auto measureMain = std::make_shared<MeasurePerformance>();
    const auto measureObjects = std::make_shared<MeasurePerformance>();
    measureMain->start();
#endif

    //Initialization flag
    bool success = true;

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    //Initialize
    if (success && !ENGINE->gRenderer->init())
    {
        printf("failed to initialize renderer \n");
    }

    GAME->gGameManager = std::make_shared<GameManager>();
    GAME->gGameManager->init();
    const auto gameClock = std::make_shared<GameClock>();
    gameClock->init();

    //Event handler
    SDL_Event e;
#if MEASURE_PERFORMANCE
    measureMain->end("Time for initialization: ");
#endif

    while (!ENGINE->gQuit)
    {
#if MEASURE_PERFORMANCE
        printf("--------------------------------------------------- \n"); 
        measureMain->start();
#endif

        gameClock->startTick();

        //Clear everything in delete queue
        ENGINE->gQueueForDelete.clear();
        ENGINE->gSizeQueueForDelete = 0;

        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                Log::print("Quit in main");
                ENGINE->gQuit = true;
            }

            //Handle button events
            for (int i = 0; i < ENGINE->gTotalButtons; ++i)
            {
                //Check if click event is handled
                if(ENGINE->gButtons[i]->handleEvent(&e))
                {
                    break;
                }
            }
        }
#if MEASURE_PERFORMANCE
        measureMain->end("Start main loop and handle input: ");
#endif

        ENGINE->notify(HANDLE_INPUT);

        //Update alle Objects
#if MEASURE_PERFORMANCE
        measureMain->start();
#endif

        for (int object = 0; object < ENGINE->gTotalObjects; ++object)
        {
            if (ENGINE->gObjectList[object])
            {
#if MEASURE_PERFORMANCE
                measureObjects->start();
#endif
                if (ENGINE->gObjectList[object]->shouldUpdate)
                {
                    ENGINE->gObjectList[object]->update();
                }
#if MEASURE_PERFORMANCE
                measureObjects->end("  " + std::to_string(object) + ". " + ENGINE->gObjectList[object]->name + ":");
#endif
            }
#if MEASURE_PERFORMANCE
            measureMain->end("All objects updated: ");
#endif
        }
        //Render Scene
#if MEASURE_PERFORMANCE
        measureMain->start();
#endif
        ENGINE->gRenderer->renderUpdate();
#if MEASURE_PERFORMANCE
        measureMain->end("render loop finished: ");
#endif
        
        //Delete Objects waiting in queue
// #if MEASURE_PERFORMANCE
//             measureMain->start();
// #endif
//         for (int objectIndex = 0; objectIndex < ENGINE->gSizeQueueForDelete; ++objectIndex)
//         {
//             if (ENGINE->gQueueForDelete[objectIndex])
//             {
//                 // ENGINE->gQueueForDelete[objectIndex]->close();
//             }
//         }
#if MEASURE_PERFORMANCE
            measureMain->end("handle queue for delete: ");
#endif

        //End of Tick
        gameClock->endTick();
    }

    //Shutdown Systems
    ENGINE->gRenderer->close();
    gameClock->close();
    
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
    
    return 0;
}
