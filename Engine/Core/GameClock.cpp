#include "GameClock.h"

#include <iostream>

#include "..\EngineSingelton.h"

void GameClock::init()
{
    pFrameTimes = new std::chrono::duration<double> [numFrameTimes];

    //fill pFrame Times with 0.0167
    for (size_t t = 0; t < numFrameTimes; ++t)
        pFrameTimes[t] = std::chrono::duration<double>{1.0 / 60.0};
}

void GameClock::close()
{
    //Clear pointer
    pFrameTimes = nullptr;

    delete this;
}

void GameClock::startTick()
{
    //Get current time before tick
    tickBeginning = std::chrono::high_resolution_clock::now();
}

void GameClock::endTick()
{
    //Get current Time after Tick
    tickEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = tickEnd - tickBeginning;
    
    // make sure the elapsed time is not too large
    if (elapsedTime > maxElapsedTime)
        elapsedTime = maxElapsedTime;

    // calculate the average frame time
    pFrameTimes[frameTimeIndex] = elapsedTime;
    frameTimeIndex = (frameTimeIndex + 1) % numFrameTimes;
    elapsedTime = std::chrono::duration<double>{0.0};

    //Calc Average
    for (size_t t = 0; t < numFrameTimes; ++t)
        elapsedTime += pFrameTimes[t];
    elapsedTime /= static_cast<double>(numFrameTimes) * 1000;

    //Update delta Time in Singleton
    DELTA_TIME = static_cast<float>(elapsedTime.count());
}

GameClock::GameClock()
{
    printf("construct Game Clock \n");
}

GameClock::~GameClock()
{
    printf("destroy Game Clock \n");
}
