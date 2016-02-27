/*
The following program takes in a temperature in Celsius and con-
verts it to Kelvin. This code has many errors in it. Find the errors, list
them and correct the code
*/


#include "std_lib_facilities.h"
double ctok(double c)
{
	int k = c - 273.15;
	return k;
}

int main()
{
	
	double c=0; // declare input variable
	cin >> d; // retrieve temperature to input variable
	double k = ctok("c"); // convert temperature
	Cout << k << "\n";

}