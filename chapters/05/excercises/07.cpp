/*

*/


#include "std_lib_facilities.h"

void solve_and_print_result(double a, double b, double c) 
{
	if (0 == a) {
		throw runtime_error("a should not be equal to zero");
	}
	
	double d = b*b - 4*a*c;
	if (d < 0) {
		throw runtime_error("No solution for quadratic equation");
	}
	
	double x1 = (-b + sqrt(d)) / (2*a);
	double x2 = (-b - sqrt(d)) / (2*a);
	cout << "The solution is: x1=" << x1 << ", x2=" << x2; 
}

int main()
{
	double a,b,c;
	cout << "Please enter a (a!=0), b and c of quadratic equation as floating-point numbers:";
	cin >> a >> b >> c;
	try {
		
		solve_and_print_result(a, b, c);
		return 0;
		
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
}