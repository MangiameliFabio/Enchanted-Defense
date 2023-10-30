#pragma once
#include <string>

struct Vector;

class Log
{
public:
    static void print(float floatToPrint, std::string message = "");
    static void print(int intToPrint, const std::string& message = "");
    static void print(const Vector& vectorToPrint, std::string message = "");
    static void print(const std::string& stringToPrint);
    static void printBool(bool boolToPrint);


};
