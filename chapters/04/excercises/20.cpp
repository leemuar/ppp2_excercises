/*
Modify the program from excercise 10 so that when you enter a name, the
program will output the corresponding score or name not found
*/


#include "std_lib_facilities.h"

// checks if the name provided is already in a vector of names
bool is_name_unique(string name, vector<string> names) {
	// check all elements in vector for the same value as "name"
	for (string n : names){
		// same value as "name" found in vector, "name" is not unique
		if (name == n) { return false; }
	}
	// checked all names in vector - no such name found, name is unique
	return true;
}

// checks name and score for input terminating values
bool is_stop_input(string name, int score) {
	return ("NoName" == name) && (0 == score);
}

// outputs names and corresponding scores
void output_names_and_scores(vector<string> names, vector<int>scores) {
	cout << "Here are all names and scores entered:\n";
	// vectors names and scores are parallel - they have equal size
	for (int i = 0; i < names.size(); ++i) {
		cout << '(' << names[i] << ',' << scores[i] << ')' << '\n';
	}	
}

// outputs the message of input data being recieved successfully
void output_successful_input(string name, int score) {
	cout << "+ added (" << name << "," << score << ")\n";
}

int main() {
		
	vector<string> names;
	vector<int> scores;
	
	string name;
	int score;	
	
	// read input
	cout << "Please enter set of names and scores: i.e. John 17 Jane 1 etc\n";
	cout << "Enter 'NoName 0' to stop input\n";
	bool stop_input = false;
	while (!stop_input){
		// read input data
		cin >> name >> score;
		if (is_stop_input(name, score)) {
			stop_input = true;
		} else {
			// terminate if nonunique name was provided
			if (!is_name_unique(name, names)) {
				simple_error("Name entered is not unique: " + name + ". Please provide unique names");
			}
			// store input in containers
			names.push_back(name);
			scores.push_back(score);
			output_successful_input(name, score);
		}
	}
	// write pairs name - score
	output_names_and_scores(names, scores);
	

}