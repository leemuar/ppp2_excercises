/*
The following program takes in a temperature in Celsius and con-
verts it to Kelvin. This code has many errors in it. Find the errors, list
them and correct the code
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
	double k = ctok(c); // convert temperature
	cout << c << " in Celsius is " << k << " in Kelvin\n";

}