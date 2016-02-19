/* 
If we define the median of a sequence as "a number so that 
exactly as many elements come before it in the sequence as come after it",
fix the program in 4.6.3 so that it always prints out a median. 
Hint: A median need not be an element of the sequence
*/


#include "std_lib_facilities.h"



// computes median from vector of double numbers
// vector should be sorted before the function call to get a correct result
double median(vector<double> numbers){
	
	// 1. compute difference between largest and smallest
	// 2. take half of the difference
	// 3. add half of the difference to smallest number (or substract from largest) to get median
	return numbers[0] + ((numbers[numbers.size() - 1] - numbers[0])/2);
	
}



//computes sum of all numbers in vector
double sum(vector<double> numbers){
	
	double sum = 0.0;
	for (double n: numbers){ sum += n; }
	
	return sum;
}



// computes average from vector of numbers
double average(vector<double> numbers){
	
	return sum(numbers) / numbers.size();
	
}



void output_all_numbers(vector<double> numbers){
	
	cout << "Here is all the numbers: ";
	for (double n: numbers){
		cout << '\t' << n;
	}
	cout << '\n';

}



void output_average(double avg){
	
	// compute mean temperature
	cout << "Average temperature: " << avg << std::endl;
	
}



// outputs median of numbers in vector
void output_median(double med){

	// output median temperature. make sure vector is sorted before calling median()
	cout << "Median temperature: " << med << '\n';

}



int main(){

	cout << "Please enter temperatures (as floating-point numbers)" << std::endl;
	cout << "Press CTRL+D to process entered numbers" << std::endl;
	vector<double> temps;
	for(double temp; cin >> temp;){
		temps.push_back(temp);
	}
	
	// sort entered temperature numbers
	sort(temps);
	
	// output all entered temperatures
	output_all_numbers(temps);
	// output average temperature
	output_average( average(temps) );
	// output median temperature
	output_median( median(temps) );
	
}