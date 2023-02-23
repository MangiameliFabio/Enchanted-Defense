#include "Helper.h"

#include <cmath>

bool Helper::epsilonComparison(const float a, const float b, const float epsilon)
{
    const float delta = abs(a - b);

    return delta < epsilon;
}
