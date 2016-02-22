/*
Try to calculate the number of rice grains that the inventor asked for in
excercise 8 above. You'll find that the number is so large that it won't fit
in an int or a double. Observe what happens shen the number gets too
large to represent exactly as an int and as a double. What is a larg-
est number of squares for which you can calculate the exact number of 
grains (using an int)? What is the number of squares for which
you can calculate the approximate number of grains (using a double)?
*/


#include "std_lib_facilities.h"

void output_details(int square, int amount, int intTotal, double dblTotal){
	cout << "Square #" << square << ',';
	cout << "Grains: " << amount << ',';
	cout << "Total (int): " << intTotal << ',';
	cout << "Total (double): " <<  dblTotal << '\n';
}


int main(){
	
	constexpr int grains_on_first_square{1};
	constexpr int start_square{2};
	constexpr int max_square{64};
	
	int amount{grains_on_first_square}; // amount of grains on current square`
	int intTotal{grains_on_first_square};	// total amount of all grains as an integer
	double dblTotal{grains_on_first_square}; // total amount of all grains as an double
	int prev_amount{grains_on_first_square}; // amount of grains on previous square

	for(int square = start_square; square <= max_square; ++square){
		amount = prev_amount * 2;
		intTotal += amount;
		dblTotal += double(amount);
		prev_amount = amount;
		
		output_details(square, amount, intTotal, dblTotal);
	}
	
}