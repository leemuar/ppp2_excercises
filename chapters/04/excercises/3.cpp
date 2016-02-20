/* 
Read a sequence of double values into a vector. think of each value as
the distance between two cities along a given route. compute and print
the total distance (the sum of all distances). Find and print the smallest 
and greatest distance between two neighboring cities. Find and print the
mean distance berween two neighboring cities
*/


#include "std_lib_facilities.h"



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
	
	cout << "Here are all the numbers: ";
	for (double n: numbers){
		cout << '\t' << n;
	}
	cout << '\n';

}



void output_average(double avg){
	
	cout << "Average distance: " << avg << '\n';
	
}



void output_total_distance(double distance) {

	cout << "The total distance is " << distance << '\n'; 

}



bool is_valid_distance(double distance){

	if (distance > 0){
		return true;
	} else {
		return false;
	}

}



void report_invalid_distance(double distance){

	cout << "The distance entered is not valid: " << distance << '\n';
	cout << "Distance should be greater than zero. The value skipped\n";

}



void output_smallest(double distance){

	cout << "Smallest is: " << distance << '\n';

}



void output_largest(double distance){

	cout << "Largest is: " << distance << '\n';

}



int main(){

	// promt user to enter distance information
	cout << "Please enter a set of distances (as floating-point numbers)\n";
	cout << "Press CTRL+D to process entered numbers\n";
	
	// read distance input
	vector<double> distances;
	for(double dist; cin >> dist;){
		
		// accept only valid distance values
		if ( is_valid_distance(dist) ){
			distances.push_back(dist);
		} else {
			report_invalid_distance(dist);
		}
	}
	
	if (0 != distances.size()) {
		// sort all distance numbers
		sort(distances);
		
		// print all entered numbers (distances)
		output_all_numbers(distances);
		
		// output the total distance
		output_total_distance( sum(distances) );
		
		// output smallest number
		// vector was previously sorted. So the first element is the smallest
		output_smallest( distances[0] );
		
		// output largest number
		// vector was previously sorted. So the last element is the largest	
		output_largest( distances[distances.size() - 1]);
		
		// output mean (average) distances
		output_average( average(distances) );
	}
	
	
}