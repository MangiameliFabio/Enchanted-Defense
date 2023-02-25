#pragma once
#define F_EQUALS Helper::epsilonComparison

class Helper
{
public:
    static bool epsilonComparison(float a, float b, float epsilon = 0.001f);
};
