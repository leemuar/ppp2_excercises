/*
Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be devided by a prime number smaller than
itself) using a vector of primes in order (so that if the vector is called
primes, primes[0]==2, primes[1]==3, primes[2]==5, etc). Then write a
loop that goes from 1 to 100, checks each number to see if it is a prime,
and stores each prime found in vector. Write another loop that lists the 
primes you found. You might check your result by comparing your vector
of prime numbers with primes. Consider 2 the first prime
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

int main(){
	
	vector<int> primes{};
	for(int i = 2; i <= 100; ++i){
		if(is_prime(i)) { primes.push_back(i); }
	}
	output_primes(primes);
}