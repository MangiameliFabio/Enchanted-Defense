#include "MeasurePerformance.h"

#include <chrono>
#include <iostream>

void MeasurePerformance::start()
{
    //Get current time before tick                                  
    tickBeginning = std::chrono::high_resolution_clock::now();
}

void MeasurePerformance::end(std::string text)
{
    std::chrono::steady_clock::time_point tickEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = tickEnd - tickBeginning;

    if (elapsedTime.count() > 50)
    {
        std::cout << "\033[31m" << text << elapsedTime.count() << " ms" << std::endl;
    }
    else if (elapsedTime.count() > 20)
    {
        std::cout << "\033[33m" << text << elapsedTime.count() << " ms" << std::endl;
    }
    else
    {
        std::cout << "\033[32m" << text << elapsedTime.count() << " ms" << std::endl;
    }
}
