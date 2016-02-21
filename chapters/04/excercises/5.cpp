/*
Write a program that performs as a very simple calculator. Your calculator
should be able to handle the four basic math operations - add, substract,
multiple, and divide - on two input values. Your program should prompt
the user to enter three arguments: two double values and a character to
represent an operation. If the entry arguments are 35.6, 24.1 and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7. In chapter 6
we look at a much more sophisticated simple calculator
*/


#include "std_lib_facilities.h"

int main(){
	
	constexpr char op_add{'+'};
	constexpr char op_sub{'-'};
	constexpr char op_div{'/'};
	constexpr char op_mul{'*'};
	
	double val1;
	double val2;
	char operation{' '};
	
	cout << "Please enter two floating point numbers and operation (+,-,*,/)\n";
	cin >> val1 >> val2 >> operation;
	
	switch(operation){
	case op_add:
		cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2;
		break;
	case op_sub:
		cout << "The subtraction of " << val1 << " and " << val2 << " is " << val1 - val2;
		break;
	case op_div:
		if (0 == val2) {simple_error("division by zero!");}
		cout << "The division of " << val1 << " and " << val2 << " is " << val1 / val2;
		break;
	case op_mul:
		cout << "The multiplication of " << val1 << " and " << val2 << " is " << val1 * val2;
		break;
	default:
		cout << "Unknown operation, please use one of the following: +,-,*,/\n";
		break;
	}
	
}