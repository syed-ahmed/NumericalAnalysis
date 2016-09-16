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

// f(x) = x^3 - 2
double func(double x) {
	return pow(x, 3) - 2.0;
}


// No need to pass in variables
int main(int argc, char* argv[]) {

	// left and right brakets and mid
	double left;
	double right;
	double mid;

	// f(x) at the brackets and mid
	double fLeft;
	double fRight;
	double fMid;

	// is it a decreasing function within the brackets?
	bool decreasing;

	// User input for the initial brackets for x
	cout << "Left bracket:\t";
	cin >> left;
	cout << "Right bracket:\t";
	cin >> right;

	// If their left bracket isnt strictly less than their right bracket
	if (left >= right) {
		cout << "Improper bracketing.\n";
		return EXIT_FAILURE;
	}

	//calculate fLeft and fRight for pairity
	fLeft = func(left);
	fRight = func(right);
	fMid = func((left + right) / 2);

	// if there is no guarantee of a root between the brackets
	if (fLeft*fRight == 1) {
		cout << "Root not bracketed.\n";
		return EXIT_FAILURE;
	}

	// determine if the function if decreasing or increasing
	decreasing = fLeft > 0;


	cout << setprecision(10);

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC
	for (int i = 1; i<ITEMAX && abs(fMid) > XACC; i++) {
		cout << "Step " << i << ":\n";
		cout << "\tLeft: " << left << "\n\tRight: " << right << "\n";

		//Calculate the middle
		mid = (left + right) / 2;
		cout << "\tMid: " << mid << "\n";

		//find the f(x) at x = mid
		fMid = func(mid);
		cout << "\tf(mid): " << fMid << "\n\n";

		//set up the new values 
		fMid > 0 == decreasing ? left = mid : right = mid;

	}
	if (abs(fMid) <= XACC) return EXIT_SUCCESS;
	else return EXIT_FAILURE;
}



