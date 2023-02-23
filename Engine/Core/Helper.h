#pragma once
#define F_COMPARE Helper::epsilonComparison

class Helper
{
public:
    static bool epsilonComparison(float a, float b, float epsilon = 0.001f);
};
