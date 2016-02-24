/*
write a program that finds the min, max and mode of a sequence of
strings
*/


#include "std_lib_facilities.h"

// return how many times a value appears in a given vector of numbers
int count(string value, vector<string> words) {
	int c{0};
	for (string n : words) {
		if (n == value) { ++c; }
	}
	return c;
}

int main(){

	// promt
	cout << "Please enter some string values:\n";
	// input set of numbers
	string n;
	vector<string> words;
	while (cin >> n) {
		words.push_back(n);
	}
	
	if (0 < words.size()) {
		// set the first element as min and max
		string min = words[0];
		string max = words[0];
		string mode = " ";
		int mode_count = 0;
		// traverse the vector
		for (int i = 0; i < words.size(); ++i) {
			// check for new min value
			if (words[i] < min) { min = words[i]; }
			// check for new max value
			if (max < words[i]) { max = words[i]; }
			// check for mode
			int count_of_words = count(words[i], words);
			if (mode_count < count_of_words) {
				mode = words[i];
				mode_count = count_of_words;
			}
		}

		cout << "min: " << min << ", max: " << max << ", mode: " << mode << " (" << mode_count << ')';
	}
}