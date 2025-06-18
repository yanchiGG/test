#include "../include/math_func.h"
#include <iostream>

namespace math
{

double plus(double first_n, double second_n)
{
    return first_n + second_n;
}

double minus(double first_n, double second_n)
{
    return first_n - second_n;
}

double multiply(double first_n, double second_n)
{
    return first_n * second_n;
}

double divide(double first_n, double second_n)
{
    if (second_n == 0.0)
        throw std::invalid_argument("Division by zero");
    else
        return first_n / second_n;
}

double pow(double first_n, int power_n)
{
    if (power_n == 0)
        return 1;
    bool negative = power_n < 0;
    power_n = std::abs(power_n);
    double result = 1;

    while (power_n > 0)
    {
        if (power_n % 2 == 1)
            result *= first_n;
        first_n *= first_n;
        power_n /= 2;
    }

    return negative ? 1 / result : result;
}

int factorial(int first_n)
{
    if (first_n < 0)
        throw std::invalid_argument("Negative factorial not defined");
    if (first_n == 0 || first_n == 1)
        return 1;
    return first_n * factorial(first_n - 1);
}
}  // namespace math
