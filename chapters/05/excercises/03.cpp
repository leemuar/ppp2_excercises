/*
Absolute zero is the lowest temperature that can be reached it is -273.15 C,
or 0K. The above program, even when corrected, will produce will produce errorne-
ous results when given a temperature below this. Place a check in the 
main program that will produce an error if a temperature is given below 
-273.15 C
*/

// for bad input exception
class Bad_Input{};
// for invalid input exception
class Input_Too_Low{};

#include "std_lib_facilities.h"
double ctok(double c)
{
	double k = c - 273.15;
	return k;
}

int main()
{
	// lowest temperature possible in Celsius
	constexpr double lowest_possible = -273.15;
	// exit codes
	constexpr int ok_exit_code = 0;
	constexpr int bad_input_exit_code = 1;
	constexpr int too_low_temp_exit_code = 2;
	constexpr int unknown_error_exit_code = 3;
	
	double c=0; // declare input variable
	cout << "Please enter a temperature in Celsius (as floating-point number): ";
	cin >> c; // retrieve temperature to input variable
	try {
	
	// check for bad input
	if (!cin){ throw Bad_Input{}; }
	// check for lower boundary of temperature
	if (c < lowest_possible) { throw Input_Too_Low{}; }
	
	double k = ctok(c); // convert temperature
	cout << c << " in Celsius is " << k << " in Kelvin\n";
	
	// everyhing is just fine, terminate program nicely
	return ok_exit_code;
	
	// deal with errors
	} catch (Bad_Input){
		cerr << "Error! Temperature entered is not valid";
		return bad_input_exit_code;
	} catch (Input_Too_Low) {
		cerr << "Error! You have entered temperature lower than lowest possible value";
		return too_low_temp_exit_code;
	} catch (...){
		cerr << "Unknown error happened";
		return unknown_error_exit_code;
	}

}