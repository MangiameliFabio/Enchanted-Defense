#pragma once
#include <chrono>
#include <string>

class MeasurePerformance
{
    std::chrono::steady_clock::time_point tickBeginning;
public:
    void start();
    void end(std::string text);
};
