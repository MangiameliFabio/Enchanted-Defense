#pragma once
#include <chrono>

class GameClock
{
    std::chrono::duration<double>* pFrameTimes = nullptr;
    std::chrono::duration<double> maxElapsedTime{0.1};

    std::chrono::time_point<std::chrono::steady_clock> tickBeginning;
    std::chrono::time_point<std::chrono::steady_clock> tickEnd;

    const size_t numFrameTimes = 60;
    size_t frameTimeIndex = 0;


public:
    void init();
    void close();

    void startTick();
    void endTick();

    GameClock();
    ~GameClock();
};
