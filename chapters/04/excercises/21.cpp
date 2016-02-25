/*
Modify the program from exercise 19 so that when you enter an integer,
the program will output all the names with that score or score not found
*/


#include "std_lib_facilities.h"

vector<int> get_score_positions(int score, vector<int> scores){
	vector<int> found_indices;
	for (int i = 0; i < scores.size(); ++i) {
		if (score == scores[i]) { found_indices.push_back(i); }
	}
	return found_indices;
}

void print_score_names(int score, vector<string> names, vector<int> scores) {
	
	// find score positions(indices) in vector of all scores
	vector<int> positions = get_score_positions(score, scores);
	// if nothing to print
	if (0 == positions.size()){
		cout << "Score not found!\n";
		return;
	}
	
	cout << "Here are the names having score " << score << ":";
	for(int i : positions){
		cout << " " << names[i] << '\n';
	}
	
}

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
	
	// let the user enter score - and show names having entered score
	int requested_score;
	cout << "OK, now give me the score - and Ill show you the names with that score:\n";
	while (cin >> requested_score) {
		print_score_names(requested_score, names, scores);
	}
	

}