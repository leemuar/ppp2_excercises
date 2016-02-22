/*
Modify the "mini-calculator" from excercise 5 to accept (just) single-digits
numbers written as either digits or spelled out
*/


#include "std_lib_facilities.h"

int get_int(string s, vector<string> numbers){
	int result = -1;
	
	// check for digit reprsentation
	if(s == "0"){
		return 0;
	} else if(s == "1"){
		return 1; 
	} else if(s == "2"){
		return 2;
	} else if(s == "3"){
		return 3;
	} else if(s == "4"){
		return 4;
	} else if(s == "5"){
		return 5;
	} else if(s == "6"){
		return 6;
	} else if(s == "7"){
		return 7;
	} else if(s == "8"){
		return 8;
	} else if(s == "9"){
		return 9;
	}

	// check for word representation
	for(int i = 0; i < numbers.size(); ++i){
		if(s == numbers[i]){ return i; }
	}
	
	// return default value
	return result;
}

int main(){
	
	constexpr char op_add{'+'};
	constexpr char op_sub{'-'};
	constexpr char op_div{'/'};
	constexpr char op_mul{'*'};
	
	string val1;
	string val2;
	char operation;
	
	vector<string> numbers{"zero","one","two","three","four","five","six","seven","eight","nine"};
	
	cout << "Please enter two single digit values and operation (+,-,*,/)\n";
	while(cin >> val1 >> val2 >> operation){
		
		// try to get integer values and operation from user input
		int int_val1 = get_int(val1, numbers);
		int int_val2 = get_int(val2, numbers);
		cout << "int1 " << int_val1 << '\n';
		cout << "int2 " << int_val2 << '\n';
		
		if (-1 != int_val1 && -1 != int_val2) {
			switch(operation){
			case op_add:
				cout << "The sum of " << int_val1 << " and " << int_val2 << " is " << int_val1 + int_val2;
				break;
			case op_sub:
				cout << "The subtraction of " << int_val1 << " and " << int_val2 << " is " << int_val1 - int_val2;
				break;
			case op_div:
				if (0 == int_val2) {simple_error("division by zero!");}
				cout << "The division of " << int_val1 << " and " << int_val2 << " is " << double(int_val1) / int_val2;
				break;
			case op_mul:
				cout << "The multiplication of " << int_val1 << " and " << int_val2 << " is " << int_val1 * int_val2;
				break;
			default:
				cout << "Unknown operation, please use one of the following: +,-,*,/";
				break;
			}
			cout << '\n';
		} else {
			cout << "Unknown operand\n";			
		}
		
	}	
}