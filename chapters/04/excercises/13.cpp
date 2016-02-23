/*
Create a program to find all the prime numbers between 1 and 100. There
is a classic method for doing this, called the "Sieve of Eratosthenes". If
you don't know that method, get on the web and look it up. Write your
program using this method
*/


#include "std_lib_facilities.h"

/*
Создает и возвращает Решето Эратосфена - вектор, заполненный булевыми величинами
Значение true элемента вектора с индексом i будет значить, что
число i+lower является простым числом. А false - что не является
*/

vector<bool> create_sieve_of_eratosthenes(int lower, int max){
	
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
	// Создадим вектор, заполненный значениями true
	// Количество элементов в векторе вычисляется 
	// по формуле (ВерхняяГраница - НижняяГраница + 1)
	vector<bool> sieve(max - lower + 1, true);
	
	for(int i = lower; i*i <= max; ++i){
		
		if(sieve[i]){
		/*	int c = 0;
			int j = 0;
			while(j <= max){
				j = i*i + c*i;
				sieve[j] = false;
				++c;
			}
		*/
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
/*
vector<int> primes(int lower, int max){
	
	// получим Решето Эратосфена - вектор, заполненный булевыми значениями
	// значение true элемента вектора с индексом i будет значить, что
	// число i+lower является простым числом. А false - что не является
	vector<bool> sieve = create_sieve_of_eratosthenes(lower, max);
	
	// посчитаем количество простых чисел в Решете
	// Используем это число позже для оптимизации создания
	// итогового вектора со списком простых чисел, чтобы избежать
	// лишней аллокации памяти c vector.push_back()
	int amount = 0;
	for(int i = 0; i < sieve.size(); ++i){ ++amount; }
	
	// создадим вектор для итоговых значений
	vector<int> prime_numbers(amount);
	// заполним итоговый вектор простыми числами из Решета
	int next_index = 0;
	for(int i = 0; i < sieve.size(); ++i){
		if(sieve[i]){
			prime_numbers[next_index] = i + lower;
		}
	}
	
	return prime_numbers;
	
}
*/

void output_primes(vector<int> primes, int lower, int max){
	
	cout << "Here is all prime numbers from " << lower << " to " << max << ":\n";
	
	for(int i: primes){
		cout << ' ' << i;
	}
	
}

int main(){
	
	int lower{2};
	int max{100};
	
	vector<bool> primes(10);
	//vector<int> prime_numbers = primes(lower, max);
	//output_primes(prime_numbers, lower, max);
	
}