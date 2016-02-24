/*
Write a program to solve quadratic equation. A quadratic equation is of
the form

ax^2 + bx + c = 0

If you don't know the quadratic formula for solving such an expression,
do some research. Remember, researching how to solve a problem is of-
ten necessary before a programmer can teach the computer how to solve
it. Use doubles for the user input for a, b and c. Since there are two
solutions to a quadratic equation, output both x1 and x2.
*/


#include "std_lib_facilities.h"

void output_equation(double a, double b, double c){
	cout << a << "x^2 + " << b << "x + " << c << '\n';
}



int main(){
	
	double a,b,c;
	double x1, x2;
	cout << "Please enter a (a!=0), b and c of quadratic equation as floating-point numbers:";
	cin >> a >> b >> c;
	// check for wrong input
	if (0 == a) { simple_error("a should not be a zero. Please provide a correct value for a"); }
	
	// find discriminant
	double d = b*b - 4*a*c;
	if (0 == d){
		x1 = -b / (2*a);
		x2 = x1;
		output_equation(a, b, c);
		cout << "There is one solution: " << x1;
	} else if (0 < d) {
		x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
		x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
		output_equation(a, b, c);
		cout << "The solution is: x1=" << x1 << ", x2=" << x2; 
	} else {
		output_equation(a, b, c);
		cout << "There are no solution for this quadratic equation" ;
	}
}