/*
Implement a little guessing game called (for some obscure reason)
"Bulls and Cows". The program has a vector of four different integers in the
range of 0 to 9 (e.g., 1234 but not 1122) and it is the user's task to discover
those numbers by repeated guesses. Say the number to be guessed is 1234
and user guesses 1359; the response should be "1 bull and 1 cow"
because the user got one digit (1) right and in the right position (a bull)
and one digit (3) right but in the wrong position (a cow). The guessing
continues until the user gets four bulls, that is, has four digits correct
and in the correct order
*/


#include "std_lib_facilities.h"

// creates a vector of 4 int numbers from 0 to 9
// the user should find
vector<int> generate_numbers_to_guess()
{
	vector<int> numbers{1, 2, 3, 4}; // hardcoded for now
	return numbers;
}


// checks if a number is valid for bulls and cows game
bool is_valid_number(int number)
{
	return (0 <= number) and (number <= 9);
}


// check if vector has number
bool has_number(vector<int> numbers, int number)
{
	for(int current : numbers) {
		if (current == number){ return true; }
	}
	
	return false;
}


bool has_number_in_different_position(vector<int> numbers, int number, int position)
{
	for (int i = 0; i < numbers.size(); ++i) {
		if ((i != position) && (numbers[i] == number)) { return true; }
	}
	return false;
}


vector<int> read_guess_from_user(int size)
{
	constexpr int default_value{-1};
	vector<int> numbers(size, default_value);
	
	for(int position = 1; position <= size;){
		cout << "Enter the number for position " << position << ": \n";
		int input_value{default_value};
		
		if (cin >> input_value)	{
			// check if number is valid
			if (!is_valid_number(input_value)){
				cout << "The number you entered is not valid, please use numbers from 0 to 9\n";
				continue;
			}
			// all numbers should be distinct
			if (has_number(numbers, input_value)){
				cout << "The number " << input_value << " was entered before. All numbers should be distinct, please provide another number\n";
				continue;
			}
			// all check passed, store the value in vector
			numbers[position - 1] = input_value;
			++position;
		}
	}
	
	return numbers;
}


// returns how many bulls `input` vector has
// using `base` vector as right answer container
int calculate_bulls(vector<int> base, vector<int> input)
{
	int bulls = 0;
	for (int i = 0; i < base.size(); ++i){
		if (base[i] == input[i]) { ++bulls; }
	}
	return bulls;
}


bool is_cow(vector<int> numbers, int number, int position)
{
	return has_number_in_different_position(numbers, number, position); 
}


// returns how many bulls `input` vector has
// using `base` vector as right answer container
int calculate_cows(vector<int> base, vector<int> input)
{
	int cows = 0;
	
	// for each element in `input`...
	for (int position = 0; position < input.size(); ++position) {
		if (is_cow(base, input[position], position)) { ++cows; }
	}
	
	return cows;
}


int main()
{
	try
	{
		
		// create the number user should guess
		vector<int> answer = generate_numbers_to_guess();
		bool game_over = false;
		while(!game_over) {
			// read user's guess
			vector<int> guess = read_guess_from_user(answer.size());
			// check 
			int bulls = calculate_bulls(answer, guess);
			
			if (bulls == answer.size()) {
				game_over = true;
				cout << "You won!";
			} else {
				int cows = calculate_cows(answer, guess);
				cout << "bulls: " << bulls << '\n';
				cout << "cows: " << cows << '\n';
			}
		}
		
		return 0;
	// handle errors	
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
	
}