/*
Modify the program from exercise 8 to use double instead of int. Also,
make a vector of doubles containing the N-1 difference between adja-
cent values and write out that vector of difference
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
vector<double> read_numbers()
{
	double n;
	vector<double> numbers;
	cout << "Please enter some floating-point numbers. Enter | to stop\n";
	while (cin >> n) {
		numbers.push_back(n);
	}
	return numbers;
}

// calculates sum of first N elements in vector of integers
// throws exceptions on error
double calc_sum(vector<double> numbers, int amount)
{
	if (numbers.size() < amount) {
		throw runtime_error("Not enough numbers to calculate requested amount!" );
	}
	
	double sum;
	for (int i = 0; i < amount; ++i) {
		sum += numbers[i];
	}
	return sum;
}

// prints sum
void output_sum(double sum, int amount)
{
	cout << "The sum of first " << amount << " elements is " << sum << '\n'; 
}

// prints vector of difference
void output_diff_vector(vector<double> diffs)
{
	if (0 == diffs.size()) {
		cout << "Vector of difference is empty";
	} else {
		cout << "Here is the vector of difference between adjacent values:\n";
		for (double d : diffs) {
			cout << ' ' << d;
		}
	}
	cout << '\n';
}

// returns vector of difference between numbers in provided vector
// returns empty vector if difference cannot be calculated (i.e. there is only one
// element in source vector)
vector<double> calc_diff_vector(vector<double> sourcev)
{
	vector<double> diffs;

	if (sourcev.size() > 1) {
		// fill the diff vector
		// start from second element
		for (int i = 1; i < sourcev.size(); ++i) {
			diffs.push_back(sourcev[i] - sourcev[i - 1]);
		}
	}
	
	return diffs;
}

int main()
{
	try {
		// read N - amount of numbers to calculate sum of
		int amount = read_amount();
		// read set of numbers
		vector<double> numbers = read_numbers();
		// output sum
		output_sum(calc_sum(numbers, amount), amount);
		// output diff numbers
		output_diff_vector(calc_diff_vector(numbers));
		
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
}