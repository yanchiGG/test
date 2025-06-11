#include <iostream>
#include <string>
#include "math_func.h"
#include <charconv>

bool isNumber(const std::string& input_s){
	double value;
	const char* str = input_s.c_str();
	const char* end = str + input_s.size();

	auto result = std::from_chars(str, end, value);
	return result.ec == std::errc() && result.ptr == end;
}


double toNumber(const std::string& input_s){
	if(isNumber(input_s)) return std::stod(input_s);
	else return 0;
}

bool isOperator (std::string& op){
	
	if( op != "+" && op != "-" && op != "*" && op != "/" && op != "^" && op != "!" /*&& op != "c" && op != "q"*/) return false;
	else return true;
		
}

double makeOperation(double first_n, double second_n, std::string& opStr){
	
	char op = opStr[0];
	switch (op) {
		case '+':
			return math::plus(first_n, second_n);
		case '-':
			return math::minus(first_n, second_n);
		case '*':
			return math::multiply(first_n, second_n);
		case '/':
			return math::devide(first_n, second_n);
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

int main(){

	std::string command {""};
	std::cout << "Enter the number" << std::endl;
	
	std::cin >> command;
	
	while(!isNumber(command) && command != "q"){
		std::cout << "Incorrect number" << std::endl;
		std::cin >> command;
	}

	double result(toNumber(command));

	while(command != "q"){

		std::string op {""};
		std::cin >> op;
		while(!isOperator(op) && op != "q" && op != "c"){ 
			std::cout << "Incorrect operator" << std::endl;
			std::cin >> op;
		}
		
		if(op == "q") break;

		if(op == "c") result = makeOperation(result, 0, op);

		if(op != "!" ) std::cin >> command;
	
		while(!isNumber(command) && command != "q"){
			std::cout << "Incorrect number" << std::endl; 
			std::cin >> command;
		}
		
		double second_n = toNumber(command);

		result = makeOperation(result, second_n, op);
		std::cout << "Result: " << result << std::endl;
	}
	return 0;	
}
