/*
In the drill, you wrote a program that, given a series of numbers, found
the max and min of that series. The number that appears the most times
in a sequence is called the mode. Create a program that finds the mode of
a set of positive integers.
*/


#include "std_lib_facilities.h"

// return how many times a value appears in a given vector of numbers
int count(int value, vector<int> numbers) {
	int c{0};
	for (int n : numbers) {
		if (n == value) { ++c; }
	}
	return c;
}

// outputs the vector with numbers
void output_number(vector<int> numbers) {
	cout << "Here are all the number:";
	for (int n : numbers){
		cout << ' ' << n;
	}
	cout << '\n';
}

int main(){

	// promt
	cout << "Please enter some integer values:\n";
	// input set of numbers
	int n{0};
	vector<int> numbers;
	while (cin >> n) {
		numbers.push_back(n);
	}
	
	if (0 < numbers.size()) {
		// set the first element as min and max
		int min = numbers[0];
		int max = numbers[0];
		int mode = 0;
		int mode_count = 0;
		// traverse the vector
		for (int i = 0; i < numbers.size(); ++i) {
			// check for new min value
			if (numbers[i] < min) { min = numbers[i]; }
			// check for new max value
			if (max < numbers[i]) { max = numbers[i]; }
			// check for mode
			int count_of_numbers = count(numbers[i], numbers);
			if (mode_count < count_of_numbers) {
				mode = numbers[i];
				mode_count = count_of_numbers;
			}
		}
		output_number(numbers);
		cout << "min: " << min << ", max: " << max << ", mode: " << mode << " (" << mode_count << ')';
	}
}