#include <gtest/gtest.h>
#include "../include/math_func.h"

// math::plus
TEST(MathTest, Plus)
{
    EXPECT_DOUBLE_EQ(math::plus(5.0, 2.0), 7.0);
    EXPECT_DOUBLE_EQ(math::plus(2.0, 5.0), 7.0);
    EXPECT_DOUBLE_EQ(math::plus(-5.0, -2.0), -7.0);
    EXPECT_DOUBLE_EQ(math::plus(5.0, -2.0), 3.0);
    EXPECT_DOUBLE_EQ(math::plus(-5.0, 2.0), -3.0);
    EXPECT_DOUBLE_EQ(math::plus(0.0, 2.0), 2.0);
    EXPECT_DOUBLE_EQ(math::plus(5.0, 0.0), 5.0);
    EXPECT_DOUBLE_EQ(math::plus(0.0, 0.0), 0.0);
}

// math::minus
TEST(MathTest, Minus)
{
    EXPECT_DOUBLE_EQ(math::minus(5.0, 2.0), 3.0);
    EXPECT_DOUBLE_EQ(math::minus(2.0, 5.0), -3.0);
    EXPECT_DOUBLE_EQ(math::minus(-5.0, -2.0), -3.0);
    EXPECT_DOUBLE_EQ(math::minus(5.0, -2.0), 7.0);
    EXPECT_DOUBLE_EQ(math::minus(-5.0, 2.0), -7.0);
    EXPECT_DOUBLE_EQ(math::minus(0.0, 2.0), -2.0);
    EXPECT_DOUBLE_EQ(math::minus(5.0, 0.0), 5.0);
    EXPECT_DOUBLE_EQ(math::minus(0.0, 0.0), 0.0);
}

// math::multiply
TEST(MathTest, Multiply)
{
    EXPECT_DOUBLE_EQ(math::multiply(5.0, 2.0), 10.0);
    EXPECT_DOUBLE_EQ(math::multiply(2.0, 5.0), 10.0);
    EXPECT_DOUBLE_EQ(math::multiply(-5.0, -2.0), 10.0);
    EXPECT_DOUBLE_EQ(math::multiply(5.0, -2.0), -10.0);
    EXPECT_DOUBLE_EQ(math::multiply(-5.0, 2.0), -10.0);
    EXPECT_DOUBLE_EQ(math::multiply(0.0, 2.0), 0.0);
    EXPECT_DOUBLE_EQ(math::multiply(5.0, 0.0), 0.0);
    EXPECT_DOUBLE_EQ(math::multiply(0.0, 0.0), 0.0);
}

// math::divide
TEST(MathTest, Divide)
{   
    EXPECT_DOUBLE_EQ(math::divide(5.0, 2.0), 2.5);
    EXPECT_DOUBLE_EQ(math::divide(2.0, 5.0), 0.4);
    EXPECT_DOUBLE_EQ(math::divide(-5.0, -2.0), 2.5);
    EXPECT_DOUBLE_EQ(math::divide(5.0, -2.0), -2.5);
    EXPECT_DOUBLE_EQ(math::divide(-5.0, 2.0), -2.5);
    EXPECT_DOUBLE_EQ(math::divide(0.0, 2.0), 0.0);
    EXPECT_THROW(math::divide(1.0, 0.0), std::invalid_argument);
}

// math::pow
TEST(MathTest, Pow)
{
    EXPECT_DOUBLE_EQ(math::pow(5.0, 2.0), 25.0);
    EXPECT_DOUBLE_EQ(math::pow(2.0, 5.0), 32.0);
    EXPECT_DOUBLE_EQ(math::pow(-5.0, -2.0), 0.04);
    EXPECT_DOUBLE_EQ(math::pow(5.0, -2.0), 0.04);
    EXPECT_DOUBLE_EQ(math::pow(-5.0, 2.0), 25.0);
    EXPECT_DOUBLE_EQ(math::pow(0.0, 2.0), 0.0);
    EXPECT_DOUBLE_EQ(math::pow(5.0, 0.0), 1.0);
    EXPECT_DOUBLE_EQ(math::pow(0.0, 0.0), 1.0);
}

// math::factorial
TEST(MathTest, Factorial)
{
    EXPECT_EQ(math::factorial(0), 1);
    EXPECT_EQ(math::factorial(1), 1);
    EXPECT_EQ(math::factorial(5), 120);
    EXPECT_THROW(math::factorial(-3), std::invalid_argument);
}
