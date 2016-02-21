/*
Write a program to play a number guessing game. The user thinks of a 
number between 1 and 100 and your program asks questions to figure 
out what the number is (e.g., "Is the number you are thinking of less than
50?"). Your program should be able to identify the number after asking
no more than seven questions. Hint: Use the < and <= operators and the
if-else construct.
*/


#include "std_lib_facilities.h"

int median(int a, int b){
	return b - ((b - a)/2);
}

int main(){
	
	constexpr int min{1};
	constexpr int max{100};
	constexpr char answer_yes{'y'};
	constexpr char answer_no{'n'};
	
	// promt
	cout << "Pick an integer number between " << min << " and " << max << "\n";
	cout << "The program will try to guess it by asking you several questions\n";
	cout << "Please enter character 'y' to answer yes and 'n' for no\n";
	
	char usr_answer;
	int top{max}; // top search boundary
	int bot{min}; // bottom search boundary
	while(bot != top){
		int med = median(bot, top);
		cout << "Is the number you guessed less than " << med << "?\n";
		cin >> usr_answer;
		switch(usr_answer){
		case answer_yes:
			// users said yes
			// Since we ask "is it less" (and not "less or equal")
			// set the top boundary to median - 1
			top = med - 1;
			break;
		case answer_no:
			// user said no
			bot = med;
			break;
		default:
			//invalid input
			cout << "Unknown answer:" << usr_answer << ". Please use 'y' or 'n'\n";
			break;
		}
	}
	
	cout << "The number you guessed is " << bot << '\n';
	
}