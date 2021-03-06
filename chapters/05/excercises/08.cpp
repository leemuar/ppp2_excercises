/*
Write a program that reads and stores a series of integers and then com-
putes the sum of the first N integers. First ask for N, then read the values
into a vector, then calculate the sum of the first N values.
Handle all inputs. for example, make sure to give an error message if the
user asks for a sum of more numbers than there are in the vector
*/


#include "std_lib_facilities.h"

// reads N - amount of numbers - from user
// throws error if input is incorrect
int read_amount() 
{
	int n;
	cout << "Please enter the amount of integers: ";
	cin >> n;
	
	if (!cin) {
		throw runtime_error("Invalid amount provided (N)");
	}
	
	if (n < 1) {
		throw runtime_error("Amount (N) should be positive integer");
	}
	
	return n;
}

//reads set of integer numbers
vector<int> read_numbers()
{
	int n;
	vector<int> numbers;
	cout << "Please enter some integers. Enter | to stop\n";
	while (cin >> n) {
		numbers.push_back(n);
	}
	return numbers;
}

// calculates sum of first N elements in vector of integers
// throws exceptions on error
int calc_sum(vector<int> numbers, int amount)
{
	if (numbers.size() < amount) {
		throw runtime_error("Not enough numbers to calculate requested amount!" );
	}
	
	int sum;
	for (int i = 0; i < amount; ++i) {
		sum += numbers[i];
	}
	return sum;
}

// prints sum
void output_sum(int sum, int amount)
{
	cout << "The sum of first " << amount << " elements is " << sum; 
}

int main()
{
	try {
		// read N - amount of numbers to calculate sum of
		int amount = read_amount();
		// read set of numbers
		vector<int> numbers = read_numbers();
		// calculate sum
		int sum = calc_sum(numbers, amount);
		// output sum
		output_sum(sum, amount);
		
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
}