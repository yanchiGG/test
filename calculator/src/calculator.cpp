#include <charconv>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_set>
#include "../include/math_func.h"

std::optional<double> parseNumber(const std::string& s)
{
    double value;
    auto result = std::from_chars(s.data(), s.data() + s.size(), value);

    if (result.ec == std::errc() && result.ptr == s.data() + s.size())
    {
        return value;
    }
    else
    {
        return std::nullopt;
    }
}

bool isOperator(std::string& op)
{
    const std::unordered_set<std::string> valid_ops = {"+", "-", "*", "/", "^", "!", "c", "q"};
    return valid_ops.count(op) > 0;
}

double makeOperation(double first_n, double second_n, std::string& opStr)
{
    char op = opStr[0];
    switch (op)
    {
        case '+':
            return math::plus(first_n, second_n);
        case '-':
            return math::minus(first_n, second_n);
        case '*':
            return math::multiply(first_n, second_n);
        case '/':
            return math::divide(first_n, second_n);
        case '^':
            return math::pow(first_n, second_n);
        case '!':
            return math::factorial(first_n);
        case 'c':
            return 0;
        default:
            return 0;
    }
}

std::optional<double> getValidNumber(std::string& input)
{
    std::cin >> input;
    auto number = parseNumber(input);
    if (input == "q")
        return std::nullopt;
    while (!number)
    {
        std::cout << "Incorrect number\n";
        std::cin >> input;
        number = parseNumber(input);
        if (input == "q")
            return std::nullopt;
    }
    return number;
}

bool getValidOperator(std::string& op)
{
    std::cin >> op;

    if (op == "q" || op == "c")
        return true;

    while (!isOperator(op))
    {
        std::cout << "Incorrect operator\n";
        std::cin >> op;
        if (op == "q" || op == "c")
            return true;
    }
    return true;
}

int main()
{
    std::string command;
    std::cout << "Enter the number\n";

    double result = *getValidNumber(command);

    while (true)
    {
        std::string op;
        if (!getValidOperator(op))
            break;
        if (op == "q")
            break;
        if (op == "c")
        {
            result = 0;
            std::cout << "Result: " << result << "\n";
            continue;
        }
        double second_n = 0;
        if (op != "!")
        {
            second_n = *getValidNumber(command);
            if (!second_n)
                break;
        }
        try
        {
            result = makeOperation(result, second_n, op);
            std::cout << "Result: " << result << "\n";
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
