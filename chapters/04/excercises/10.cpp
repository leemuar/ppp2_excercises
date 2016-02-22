/*
Write a program that plays the game "Rock, paper, scissors". If you are not
familiar with the game do some research (e.g., on the web using Google).
Research is a common task for a programmers. Use a switch statement to
solve this excercise. Also, the machine should give random answers (i.e.,
select the next rock, paper or scissors randomly). Real randomness is too
hard to provide just now, so just build a vector with a sequence of values
to be used "as next value". If you build the vector into the program,
it will always play the same game, so maybe you should let the user en-
ter some values. Try variations to make it less easy for the user to guess
which move the machine will make next
*/


#include "std_lib_facilities.h"

bool is_valid_input(char c){
	return ('r' == c) || ('p' == c) || ('s' == c);
}

int answer_as_int(char answer){
	
	constexpr int rock{0};
	constexpr int paper{1};
	constexpr int scissors{2};
	
	switch(answer){
	case 'r': 
		return rock;
		break;
	case 'p':
		return paper;
		break;
	case 's':
		return scissors;
		break;
	default:
		return -1;
		break;
	}
}

int compare(int val1, int val2){
	
	constexpr int rock{0};
	constexpr int paper{1};
	constexpr int scissors{2};
	
	if (val1 == val2){ return 0; }
	if ((rock == val1 && scissors == val2) || (paper == val1 && rock == val2) || (scissors == val1 && paper == val2)){ 
		return 1;
	} else {
		return -1;
	}
}

int calc_next(int size, int index, int shift){
	if (index + shift > size - 1){
		return 0;
	} else {
		return index + shift;
	}
}

void output_promt(){
	cout << " Rock(r), paper(p) or scissors(s)? ";
}

vector<int> input_pool(){
	
	// character need to be entered to stop input
	constexpr char exit{'e'};
	
	cout << "Please multiple characters: 'r' for rock, p for paper, s for scissors\n";
	cout << "Enter 'e' to confirm\n";

	char input;	
	vector<int> pool;
	while(cin >> input){
		if(exit == input){ return pool; }
		if(is_valid_input(input)){
			pool.push_back(answer_as_int(input));
		} else {
			cout << "Unknown char: " << input << ". Please use r, p or s\n";
		}
	}

}


int main(){
	
	// let the user input pool of values (rock, paper, scissors)
	vector<int> pool = input_pool();
	
	int shift{1};
	int next{0};
	char input;
	
	//start the game
	output_promt();
	while(cin >> input){
		if(is_valid_input(input)){
			switch(compare(answer_as_int(input),pool[next])){
			case -1:
				cout << "I won!";
				break;
			case 0:
				cout << "Draw! We guessed the same!";
				break;
			case 1:
				cout << "You won!";
				break;
			}
			next = calc_next(pool.size(), next, shift);
		} else {
			cout << "Invalid answer, please use r for rock, p for paper, s for scissors\n";
		}
		output_promt();
	}
	
}