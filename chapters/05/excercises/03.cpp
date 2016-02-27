/*
Absolute zero is the lowest temperature that can be reached it is -273.15 C,
or 0K. The above program, even when corrected, will produce will produce errorne-
ous results when given a temperature below this. Place a check in the 
main program that will produce an error if a temperature is given below 
-273.15 C
*/


#include "std_lib_facilities.h"
double ctok(double c)
{
	double k = c - 273.15;
	return k;
}

int main()
{
	
	double c=0; // declare input variable
	cout << "Please enter a temperature in Celsius (as floating-point number): ";
	cin >> c; // retrieve temperature to input variable
	if (cin){
		double k = ctok(c); // convert temperature
		cout << c << " in Celsius is " << k << " in Kelvin\n";
	} else {
		cout << "Error! Wrong temperature provided! Please enter a floating point number\n";
	}

}