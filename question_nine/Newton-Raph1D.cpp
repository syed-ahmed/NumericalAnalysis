// Root-finding: Secant Method code
//
// J. Faber, for MATH-411 (RIT)
// GPL, etc.
//
// call it with ./secant x1 x2
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
int ITEMAX = 200;
// Tolerance for finding a root
double XACC = 1.0e-12;

double B = 0.04;
double S = 0.0011111;
double Q = 0.083333;
double D = 1.29074;
double N = -1.774598;

//suplementary function for func
double V(double W){
	double val = (Q + S*(B + 2 * W) / pow(W,2)) / (B + pow(W,2));
	return val;
}


//Functions to try
void func(double W, double& funcval, double& derivval) {
	funcval = (-B*(1 + V(W))) / W + S / (2 * pow(W, 2)) - W + (((1 - V(W))*W + 1)*pow(1 - V(W), 1 / 2)) / 2;
	derivval = //derive of above
}

int main(int argc, char* argv[]) {

	// You pass in the initial guess for x
	double xnew = atof(argv[1]);

	int i;
	double diff = 10.0*XACC;

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC

	for (i = 0; i<ITEMAX && abs(diff) > XACC; i++) {

		double xold = xnew;

		double funcval, derivval;
		func(xold, funcval, derivval);
		diff = funcval / derivval;
		xnew = xold - diff;

		cout << "i:" << i << setprecision(12) << setw(20) << " xold,new:" << xold << "     " << xnew << "     diff:    " << diff << endl;

	}

	cout << setprecision(15) << "root:" << xnew << " error:" << diff << endl;

	return 0;
}



