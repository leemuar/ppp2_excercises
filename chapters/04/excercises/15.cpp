/*
Write  a program that takes an input value n and then finds the first n primes
*/


#include "std_lib_facilities.h"

// проверяет является ли число простым
// для вычисления требует список(вектор) уже известных (вычисленных) простых чисел
bool is_prime(int number, vector<int> primes){
	for(int n: primes){
		if(0 == (number%n)){ return false; }
	}
	return true;
}

// печатает вектор с простыми числами
void output_primes(vector<int> primes){
	cout << "Here are the first " << primes.size() << " prime numbers: ";
	for(int n: primes){
		cout << ' ' << n;
	}
}

int main(){

	constexpr int first_prime{2};
	// promt user
	cout << "Please enter how many first prime numbers should be calculated: ";
	// read user input
	int max{0};
	cin >> max;
	// check input...
	if(max < 1){
		// ... bad input provided
		cout << "Wrong number provided: " << max << ". Expected it to be > 1";
	} else {
		// ...input OK
		// calculate prime numbers
		// Реализация с заполнением вектора через push_back()
		// не оптимальная с точки зрения выделения памяти,
		// но проще. Поэтому пока пусть так.
		vector<int> primes(1, first_prime);
		for(int n=first_prime; primes.size() < max; ++n){
			if(is_prime(n, primes)){
				primes.push_back(n);
			}
		}
		// output prime numbers found
		output_primes(primes);
	}
	
}