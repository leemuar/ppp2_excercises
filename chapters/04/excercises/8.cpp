/*
Ther is and old story that the emperor wanted to thank the inventor of
the game of the chess and asked the inventor to name his reward. The inven-
tor asked for one grain of rice for the first square, 2 for second, 4 for
the third, and so on, doubling for each of the 64 squares. That may sound
modest, but there wasn't that much rice in the empire! Write a program to
calculate how many squares are required  to give the inventor at least 1000
grains of rice, at least 1 000 000 grains, and at least 1 000 000 000 grains.
You'll need a loop, of course, and probably an int to keep track of which
square you are at, an int to keep the number of grains on the current
square, and an int too kepp track of the grains on all previous squares. We
suggest that you write out the value of all your variables for each iteration
of the loop so that you see what's going on.
*/


#include "std_lib_facilities.h"

void output_details(int square, int amount, int total){
	cout << "Square #" << square << ',';
	cout << "Grains: " << amount << ',';
	cout << "Total: " << total << '\n';
}

int square_by_grains(int grains_required, bool output){
	constexpr int grains_on_first_square{1};
	
	int square = 1; // current square number
	int amount{grains_on_first_square}; // amount of grains on current square`
	int total{grains_on_first_square};	// total amount of all grains
	int prev_amount{grains_on_first_square}; // amount of grains on previous square
	while(amount < grains_required) {
		++square; // next square
		// calc amount on current square, total amount
		amount = prev_amount * 2;
		total += amount;
		prev_amount = amount;
		// output calculation details
		if(output){	output_details(square, amount, total); }
	}
	
	return square;
	
}

int main(){

	int grains1 = 1000;
	int grains2 = 1000000;
	int grains3 = 1000000000;
	bool print_detailed_calulation = true;
	
	int sq1 = square_by_grains(grains1, print_detailed_calulation);
	cout << "For " << grains1 << " grains you need " << sq1 << " squares\n";
	
	int sq2 = square_by_grains(grains2, print_detailed_calulation);
	cout << "For " << grains2 << " grains you need " << sq2 << " squares\n";
	
	int sq3 = square_by_grains(grains3, print_detailed_calulation);
	cout << "For " << grains3 << " grains you need " << sq3 << " squares\n";
		
}