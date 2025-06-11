#include <iostream>
#include "math_func.h"


double math::plus(double first_n, double second_n){ return first_n + second_n;}

double math::minus(double first_n, double second_n){ return first_n - second_n;}

double math::multiply(double first_n, double second_n){ return first_n * second_n;}

double math::devide(double first_n, double second_n){
	if(second_n != 0) return first_n / second_n;
	else std::cout << "You can't divide by zero" << std::endl;
}

double math::pow(double first_n, int power_n){
	if (power_n == 0) return 1;
	bool negative = power_n < 0;
	power_n = std::abs(power_n);
	double result = 1;
	
	while (power_n > 0) {
		if (power_n % 2 == 1) result *= first_n;
		first_n *= first_n;
		power_n /= 2;
	}
	
	return negative ? 1 / result : result;
}

double math::factorial(int first_n) {
	if (first_n < 0) throw std::invalid_argument("Negative factorial not defined");
	if (first_n == 0 || first_n == 1) return 1;
	return first_n * factorial(first_n - 1);
}



