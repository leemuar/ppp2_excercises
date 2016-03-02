/*
Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Fins the largest 
Fibonacci number that fits in an int.
*/


#include "std_lib_facilities.h"

constexpr int min_amount = 1;

int read_amount()
{
	int amount;
	cout << "Enter the amount of first Fibonacci numbers to output:\n";
	if (cin >> amount) {
		if (amount < min_amount) {
			throw runtime_error("Amount is less than minimal expected");
			return amount;
		}
	} else {
		throw runtime_error("Unknown amount entered");
	}
}

void output_fibonacci(int firstn)
{
	cout << "Here are the first " << firstn << " Fibonacci numbers:\n";
	
	int prev = 0;
	int current = 1;
	for (int i = 1; i <= firstn; ++i) {
		cout << current;
		prev = current;
		current += prev;
	}
}

int main()
{
	try {
		
		// read amount of first fibonacci numbers to output
		int firstn = read_amount();
		// print Fibonacci numbers
		output_fibonacci(firstn);
		
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
}