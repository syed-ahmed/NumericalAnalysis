// Root-finding: False Position Method code
//
// J. Faber, for MATH-411 (RIT)
// GPL, etc.
//
// call it with ./falsi x1 x2
//
// where you pass in the initial bounds

// These headers are so standard one tends not to even think about them
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

// Maximum number of iterations. 
int ITEMAX = 60;
// Tolerance for finding a root
double XACC = 1.0e-8;

//Let's solve for the value where x=cos x
double func(double x) {
	//  return x-cos(x);
	return pow(x, 3) - 2.0;
}

// No need to pass in variables
int main(int argc, char* argv[]) {

	// You pass in the initial brackets for x
	double left;
	double right;

	// User input for the initial brackets for x
	cout << "First guess:\t";
	cin >> left;
	cout << "Second guess:\t";
	cin >> right;

	// If their left bracket isnt strictly less than their right bracket
	if (left >= right) {
		cout << "Improper bracketing.\n";
		return EXIT_FAILURE;
	}

	double fLeft = func(left);
	double fRight = func(right);
	
	// if there is no guarantee of a root between the brackets
	if (fLeft*fRight == 1) {
		cout << "Root not bracketed.\n";
		return EXIT_FAILURE;
	}

	double appx;
	double fAppx = 10.0*XACC;

	cout << setprecision(10);

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC
	for (int i = 1; i<ITEMAX && abs(fAppx) > XACC; i++) {

		cout << "Step " << i << ":\n";
		cout << "\tLeft: " << left << "\n\tRight: " << right << "\n";

		// approximate the root via secant method
		appx = left + (right - left)*fLeft / (fLeft - fRight);
		cout << "\tappx: " << appx << "\n";

		fAppx = func(appx);
		cout << "\tf(appx): " << fAppx << "\n\n";

		// move in the appropriate bracket
		if (fAppx < 0) {
			// This is the new left bracket
			left = appx;
			fLeft = fAppx;
		}
		else {
			//This is the new right bracket
			right = appx;
			fRight = fAppx;
		}
	}
	system("pause");
	if (abs(fAppx) <= XACC) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}
