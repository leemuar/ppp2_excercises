/*
Make a vector holding the ten values "zero", "one", ... "nine".
Use that in a program that converts a digit to its corresponding
spelled-out value: e.g., the input 7 gives the output seven. Have the same
program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.
*/


#include "std_lib_facilities.h"

int main(){
	
	constexpr int index_not_found = -1;
	vector<string> numbers{"zero","one","two","three","four","five","six","seven","eight","nine"};
	
	cout << "Please enter a number as word (i.e. 'zero', 'one')\n";
	string s;
	while(cin >> s){
		// search the word in the vector
		int index{index_not_found};
		for(int i = 0; i < numbers.size() - 1; ++i){
			if(s == numbers[i]){
				index = i;
			}
		}
		
		if(index != index_not_found){
			cout << "For " << s << " it is " << index << '\n';
		} else {
			cout << "String " << s << " is not found!\n";
		}
	}
	
}

//int main(){
//	
//	vector<string> numbers{"zero","one","two","three","four","five","six","seven","eight","nine"};
//	
//	int i;
//	while(cin >> i){
//		if(i < numbers.size()){
//			cout << "Its " << numbers[i] << " for " << i << '\n';
//		} else {
//			cout << "Unknown number: " << i << '\n';
//		}
//	}
//	
//}