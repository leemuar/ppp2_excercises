/*
Modify the program described in the previous excercise to take an input
value max and then find all prime numbers from 1 to max.
*/


#include "std_lib_facilities.h"

bool is_prime(int number){
	
	for(int i = 2; i < number; ++i){
		if(0 == (number%i)){ return false; }
	}
	return true;
	
}

void output_primes(vector<int> primes){
	
	cout << "Prime numbers:";
	for(int i: primes){
		cout << ' ' << i;
	}
	cout << '\n';
	
}

int input_max(){
	
	int max;
	while(true){
		cout << "Enter a max integer value to calculate prime numbers to:\n";
		cin >> max;
		if(max > 1){
			return max;
			cout << "Wrong input! Please enter the number that is larger than 1\n";
		}
	}

}

int main(){
	
	int max = input_max();
	vector<int> primes{};
	for(int i = 2; i <= max; ++i){
		if(is_prime(i)) { primes.push_back(i); }
	}
	output_primes(primes);
}