#pragma once
#include <chrono>
#include <memory>

class GameClock
{
    std::chrono::duration<double>* pFrameTimes = nullptr;
    std::chrono::duration<double> maxElapsedTime{0.1};

    std::chrono::time_point<std::chrono::steady_clock> tickBeginning;
    std::chrono::time_point<std::chrono::steady_clock> tickEnd;

    static constexpr int numFrameTimes = 60;
    int frameTimeIndex = 0;


public:
    void init();
    void close() const;

    void startTick();
    void endTick();

    GameClock();
    ~GameClock();
};
