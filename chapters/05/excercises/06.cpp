/*
Write a program that cpnverts from Celsius to Fahrenheit and from Fahr-
enheit to Celsius (formula in 4.3.3). Use estimation (5.8) to see if your
results are plausible
*/

#include "std_lib_facilities.h"

// temperature unit constants
constexpr char unit_celsius = 'c';
constexpr char unit_fahrenheit = 'f';

// exit code constants
constexpr int exit_ok = 0;
constexpr int exit_runtime_error = 8;
constexpr int exit_unknown_error = 9;

// Numbers used in celsius-fahrenheit conversion formula
constexpr double cels_fahr_ratio = 5.0 / 9;
constexpr double fahr_cels_ratio = 9.0 / 5;
constexpr double cels_fahr_add = 32;

// checks temperature unit char
bool is_valid_unit(char unit)
{
	if (unit_celsius == unit || unit_fahrenheit == unit) {
		return true;
	}
	return false;
}

// read temperature number from input
double read_temperature()
{
	double t;
	cout << "Please enter a temperature number:\n";
	cin >> t;
	if(!cin) {
		throw runtime_error("Temperature entered is not valid");
	}
	
	return t;
}

// reads temperature unit character
char read_unit()
{
	char unit{' '};
	// read unit from input
	cin >> unit;
	// check the input
	if (!cin) {
		throw runtime_error("Valid unit to convert from was not provided");
	}
	if (!is_valid_unit(unit)) {
		throw runtime_error("Invalid unit to convert from");
	}

	return unit;
}

// reads temperature unit char to convert from
char read_unit_from()
{
	char unit{' '};
	// print promt message
	cout << "Please enter a temperature unit to convert from\n";
	cout << "Use " << unit_celsius << " for Celsius, " << unit_fahrenheit << " for Fahrenheit\n";
	// read unit from input
	cin >> unit;
	
	// check the input and throw error if required
	if (!cin) {
		throw runtime_error("Valid unit to convert from was not provided");
	}
	if (!is_valid_unit(unit)) {
		throw runtime_error("Invalid unit to convert from");
	}
	
	return unit;
}

// read temperature unit char to convert from
char read_unit_to()
{
	char unit{' '};
	// print promt message
	cout << "Please enter a temperature unit to convert to\n";
	cout << "Use " << unit_celsius << " for Celsius, " << unit_fahrenheit << " for Fahrenheit\n";
	// read unit from input
	cin >> unit;
	
	// check the input
	if (!cin) {
		throw runtime_error("Valid unit to convert from was not provided");
	}
	if (!is_valid_unit(unit)) {
		throw runtime_error("Invalid unit to convert from");
	}
	
	return unit;
}

// converts temperature in Celsius to Fahrenheit
double celsius_to_fahrenheit(double temperature)
{
	return cels_fahr_ratio * temperature + cels_fahr_add;
}

// converts temperature in Fahrenheit to Celsius
double fahrenheit_to_celsius(double temperature)
{
	return fahr_cels_ratio * (temperature - cels_fahr_add);
}

// converts temperature to required unit
// For unit use c for Celsius, f for Fahrengeit
double convert(double temperature, char unit_from, char unit_to)
{
	// celsius to fahrenheit
	if (unit_celsius == unit_from && unit_fahrenheit == unit_to) {
		return celsius_to_fahrenheit(temperature);
	}
	// fahrenheit to celsius
	if (unit_fahrenheit == unit_from && unit_celsius == unit_to) {
		return fahrenheit_to_celsius(temperature);
	}
	// unknown conversion
	throw runtime_error("Unknown conversion");
	
}

// outputs result of calculation
void output_result(double temperature, char unit_from, char unit_to, double result)
{
	cout << "Convertion results: " << temperature << unit_from << " is " << result << unit_to << '\n';
}

int main()
{
	double temperature{0};
	double result{0};
	char unit_from{' '}; // temperature unit to convert from
	char unit_to{' '}; // temperature unit to convert to
	
	try {
		// read input from user
		temperature = read_temperature();
		unit_from = read_unit_from();
		unit_to = read_unit_to();
		// calculate temperature
		result = convert(temperature, unit_from, unit_to);
		// output result
		output_result(temperature, unit_from, unit_to, result);
		
		return exit_ok;
		
	// handle errors
	} catch (exception& e) {
		cerr << "Error! " << e.what();
		return exit_runtime_error;
	} catch (...) {
		cerr << "Oops! Unknown error happened!";
		return exit_unknown_error;
	}

}
