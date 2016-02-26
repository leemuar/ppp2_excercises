/*
remove all errors in program
*/


#include "std_lib_facilities.h"

int main(){
	
try {
	int x=3; 
	if (2==x) {error("zero division");} 
	double d = 6.0/(x-2);
	if (d==2*x) cout << "Success!\n";
	keep_window_open();
	return 0;
} catch(exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
} catch(...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

}