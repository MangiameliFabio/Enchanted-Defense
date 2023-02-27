#include "Helper.h"

#include <cmath>

bool Helper::epsilonComparison(const float a, const float b, const float epsilon)
{
    const float delta = abs(a - b);

    return delta < epsilon;
}

double Helper::degreeToRadian(double degree)
{
    constexpr double pi = 3.14159265358979323846264338327950288;
    return (pi / 180.0 * degree);
}
