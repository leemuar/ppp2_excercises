/*
Modify the program described in the previos exercise to take an input
value max and then find all prime numbers from 1 to max.
*/


#include "std_lib_facilities.h"

void output_primes(vector<int> primes){

	cout << "Prime numbers: ";
	for(int i: primes){
		cout << i << ' ';
	}
	cout << '\n';

}

bool is_prime(char c){
	constexpr char prime{'1'};
	return prime == c;
}

/*
Создает и возвращает Решето Эратосфена - вектор со значениями '1' и '0'
По идее лучше использовать значения boolean, но по какой-то причине vector<bool> 
не работает (см подробнее тут - http://stackoverflow.com/questions/17930442/) 
Поэтому используем тип char

Значение '1' элемента вектора с индексом i будет значить, что
число i+lower является простым числом.
*/
vector<char> create_sieve_of_eratosthenes(int lower, int max){
	
	constexpr char prime_value{'1'};
	constexpr char not_prime{'0'};
	/*
	https://ru.wikipedia.org/wiki/Решето_Эратосфена
	Вход: натуральное число n

	Пусть A — булевый массив, индексируемый числами от 2 до n, 
	изначально заполненный значениями true.

	 для i := 2, 3, 4, ..., пока i2 \le n:
	  если A[i] = true:
		для j := i2, i2 + i, i2 + 2i, ..., пока j \le n:
		  A[j] := false

	Выход: числа i, для которых A[i] = true.
	*/
	// Создадим вектор, заполненный значениями '1'
	// Количество элементов в векторе вычисляется 
	// по формуле (ВерхняяГраница - НижняяГраница + 1)
	vector<char> sieve(max - lower + 1, prime_value);
	for(int n = lower; n <= max; ++n){
		if(is_prime(sieve[n-lower])){
			int shift = 2;
			for(int i = shift*n; i <= max; i = shift*n) {
				sieve[i-lower] = not_prime;
				++shift;
			}
		}
	}
	
	return sieve;
	
}


/*
Создает и возвращает вектор со всеми натуральными простыми числами 
[lower, max] - от lower до max
lower -  нижняя граница включительно
max - верхняя граница включительно
*/
vector<int> primes(int lower, int max){
	
	vector<char> sieve = create_sieve_of_eratosthenes(lower, max);
	
	// посчитаем количество простых чисел в Решете
	// Используем это число позже для оптимизации создания итогового вектора
	// со списком простых чисел, чтобы избежать
	// лишней аллокации памяти c vector.push_back()
	int amount = 0;
	for(int i = 0; i < sieve.size(); ++i){ 
		if(is_prime(sieve[i])) { ++amount; }
	}
	
	// создадим вектор для итоговых значений
	vector<int> prime_numbers(amount);
	// заполним итоговый вектор простыми числами из Решета
	int next = 0;
	for(int i = 0; i < sieve.size(); ++i){
		if(is_prime(sieve[i])){
			prime_numbers[next] = i + lower;
			++next;
		}
	}
	
	return prime_numbers;
	
}

int main(){
	
	cout << "Please enter a positive integer number > 1: ";
	int max{0};
	cin >> max;
	if (max < 2) { cout << "Wrong number entered: expected number greater than 1"; }
	
	output_primes(primes(2,max));
	
}