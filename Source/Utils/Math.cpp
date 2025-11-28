#include "Math.h"

#include <random>

MATH_API int LifeExe::max(int x, int y) { return x > y ? x : y; }

MATH_API int LifeExe::factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

MATH_API int LifeExe::sum(int n) { return n <= 0 ? 0 : n + sum(n - 1); }

MATH_API int LifeExe::randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr{min, max};

    return distr(gen);
}
