/*
The program ("bulls and cows" game from exercise 12) is a bit tedious because the answer is hard-coded into the
program. Make a version where user can play repeatedely (without
stopping and restarting the program) and each game has a new set of
four digits. You can get four random digits by calling the random number
generator randint(10) from std_lib_facilities.h four times. You will note
that if you run thatprogram repeatedly, it will pick the same sequence of
four digits each time you start the program. To avoid that, ask the user
to enter a number (any number) and call srand(n) where n is called a seed, and
different seeds give different sequences of random numbers
*/


#include "std_lib_facilities.h"

// creates a vector of 4 int numbers from 0 to 9
// the user should find
vector<int> generate_numbers_to_guess()
{
	vector<int> numbers{randint(10), randint(10), randint(10), randint(10)};
	return numbers;
}

// prints vector of numbers
void print_numbers(vector<int> numbers)
{
	for (int num : numbers) {
		cout << num;
	}
	cout << '\n';
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