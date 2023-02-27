#pragma once
#define F_EQUALS Helper::epsilonComparison
#define DEGREE_TO_R Helper::degreeToRadian

class Helper
{
public:
    static bool epsilonComparison(float a, float b, float epsilon = 0.001f);

    static double degreeToRadian(double degree);
};
