// Standard headers
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

// Maximum number of iterations.
int ITEMAX = 60;
// Tolerance for finding a root.
double XACC = 1.0e-8;

//constants
double k1 = 1.0;
double A1 = 1.0;
double B1 = 1.5;
double C1 = -0.25;
double k2 = 1.0;
double A2 = 4.0;
double B2 = -6.4;
double C2 = 1.5;

double Omega(double x, double k, double a, double b, double c){
    return k / (a * pow(x, 2) + b * x + c);
}

// f(x) = x^3 - 2
double func(double x) {
	return Omega(x, k1, A1, B1, C1) - Omega(x, k2, A2, B2, C2);
}

// No need to pass in variables
int main(int argc, char* argv[]) {

	// first second and third guesses
	double first;
	double second;
	double third;

	// f(x) at the brackets and third
	double fFirst;
	double fSecond;
	double fThird;

	// User input for the initial brackets for x
	cout << "First guess:\t";
	cin >> first;
	cout << "Second guess:\t";
	cin >> second;

	//calculate fFirst and fSecond for pairity
	fFirst = func(first);
	fSecond = func(second);

	// if there is no guarantee of a root between the brackets
	if (fFirst*fSecond == 1) {
		cout << "Root not bracketed.\n";
		return EXIT_FAILURE;
	}

	// Just to get the loop started
	fThird = fFirst;

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC
	for (int i = 1; i<ITEMAX && abs(fThird) > XACC; i++) {
		cout << "Step " << i << ":\n";
		cout << "\tFirst: " << first << "\n\tSecond: " << second << "\n";

		//Calculate the thirdd
		third = (first*fSecond - second*fFirst) / (fSecond - fFirst);
		cout << "\tGuess: " << third << "\n";

		//find the f(x) at x = third
		fThird = func(third);
		cout << "\tf(guess): " << fThird << "\n\n";

		//set up the new values 
		first = second;
		fFirst = fSecond;
		second = third;
		fSecond = fThird;

	}
	if (abs(fThird) <= XACC) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}


