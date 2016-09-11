#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

// Maximum number of iterations. 
int ITEMAX = 5000;
// Tolerance for finding a root
double XACC = 1.0e-8;
// constant in the function for last fpi test
double ALPHA = 0.41930965;

//Functions to try
double func(double x) {
	//return x / 2.0 + 1 / pow(x, 2.0);
	//return 2 * x / 3 + 2 / (3 * pow(x, 2));
	return x - ALPHA * (pow(x, 3) - 2);
}

int main(int argc, char* argv[]) {

	// Initial guess
	double xold;
	// new guess
	double xnew;

	//get an initial guess
	cout << "Initial guess:\t";
	cin >> xold;

	//gets the loop a-rollin'
	double diff = 10.0*XACC;

	cout << setprecision(10);

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC
	for (int i = 1; i<=ITEMAX && abs(diff) > XACC; i++) {

		cout << "Step " << i << ":\n";
		cout << "\tGuess: " << xold << "\n";

		// calculate the new guess
		xnew = func(xold);
		cout << "\tNewGuess: " << xnew << endl;

		// calculate the difference
		diff = xnew - xold;
		cout << "\tDifference: " << diff << endl;

		// set up new guess
		xold = xnew;

	}
	if (abs(diff) <= XACC) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}

