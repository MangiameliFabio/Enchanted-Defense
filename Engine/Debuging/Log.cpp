#include "Log.h"

#include "../Core/Vector.h"

void Log::print(float floatToPrint, std::string message)
{
    printf("%s %f\n", message.c_str(), static_cast<double>(floatToPrint));
}

void Log::print(int intToPrint, const std::string& message)
{
    printf("%s %f\n", message.c_str(), static_cast<double>(intToPrint));
}

void Log::print(const Vector& vectorToPrint, std::string message)
{
    printf("%s x: %f y: %f\n", message.c_str(), static_cast<double>(vectorToPrint.x),
           static_cast<double>(vectorToPrint.y));
}

void Log::print(const std::string& stringToPrint)
{
    printf("%s\n", stringToPrint.c_str());
}

void Log::printBool(bool boolToPrint)
{
    if (boolToPrint)
        printf("true");
    else
        printf("false");
}
