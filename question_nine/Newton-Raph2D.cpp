#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

void invMatrix(double arr[2][2]);

// Maximum number of iterations. 
int ITEMAX = 50;
// Tolerance for finding a root
double XACC = 1.0e-12;

double ARR[2][2];
double B = 0.04;
double S = 0.0011111;
double Q = 0.083333;
double D = 1.29074;
double N = -1.774598;

//Functions to try
void funcf(double V, double W, double& funcval, double& derivvalv, double& derivvalw) {
	funcval = V*pow((B + W), 2) - S * (B + 2 * W) / pow(W, 2) - Q;
	derivvalv = pow((B + W), 2);
	derivvalw = V * 2 * B + V * 2 * W - 2 * (W + B) / pow(W, 3);
}

void funcg(double V, double W, double& funcval, double& derivvalv, double& derivvalw) {
	funcval = -1 * B / 2 * (1 + V) + S*pow(W, -2) / 2 - W + ((1 - V)*W - D*pow((1 - V), 1 / 2)) / 2 - N;
	derivvalv = -1 * B / 2 + W / 2 - 1 / (2 * pow(1 - V, 1 / 2));
	derivvalw = -1 * S*(pow(W, -3)) - 1 - V / 2;
}

int main(void) {

	// You pass in the initial guess for v and w
	double Vnew;
	double Wnew;

	cout << "Input a guess for V:\t";
	cin >> Vnew;
	cout << "Input a guess for W:\t";
	cin >> Wnew;

	//f(V, W) = V*pow((B+W), 2) - S * (B+ 2*W) / pow(W, 2) - Q
	//g(V, W) = -1*B/2*(1+V) + S*pow(W, -2)/2 - W + ((1-V)*W - D*pow((1-V), 1/2))/2 - N
	//fv = pow((B+W), 2)
	//fw = V*2*B + V*2*W - 2*(W + B)/pow(W, 3)
	//gv = -1*B/2 + W/2 - 1/(2*pow(1-V, 1/2))
	//gw = -1*S*(pow(W, -3)) - 1 - V/2
	
	int i;
	double arrOut[2][1] = { 10.0*XACC, 10.0*XACC };
	double Vold, Wold;
	double funcvalg, funcvalf, derivvalfv, derivvalfw, derivvalgv, derivvalgw;
	//double arrderiv[2][2];

	//We loop at most ITEMAX iterations, stopping if our answer is 
	//a root to within a tolerance of XACC

	for (i = 0; i<ITEMAX && abs(arrOut[0][0]) > XACC && abs(arrOut[1][0]) > XACC; i++) {

		Vold = Vnew;
		Wold = Wnew;


		funcf(Vold, Wold, funcvalf, derivvalfv, derivvalfw);
		funcg(Vold, Wold, funcvalg, derivvalgv, derivvalgw);
		
		double arrderiv[2][2] = { derivvalfv, derivvalfw, derivvalgv, derivvalgw };

		invMatrix(arrderiv);
		arrOut[0][0] = (ARR[0][0] * funcvalf + ARR[0][1] * funcvalg);
		arrOut[1][0] = (ARR[1][0] * funcvalf + ARR[1][1] * funcvalg);
		Vnew = Vold - arrOut[0][0];
		Wnew = Vold - arrOut[1][0];

		cout << "i:" << i << setprecision(12) << setw(20) << " Vnew:" << Vnew << "     Wnew:" << Wnew << "     diffV:    " << arrOut[0][0] << "      diffW:"<< arrOut[1][0] << endl;

	}

	//cout << setprecision(15) << "root:" << xnew << " error:" << diff << endl;

	return 0;
}

void invMatrix(double arr[2][2]) { //inverts a 2x2 matrix
	double a, b, c, d, mult;
	a = arr[0][0];
	b = arr[0][1];
	c = arr[1][0];
	d = arr[1][1];

	if ((a*d - b*c) != 0)
		mult = 1 / (a*d - b*c);
	else cout << "div by 0!" << endl;

	ARR[0][0] = mult * d;
	ARR[0][1] = mult * -1 * b;
	ARR[1][0] = mult * -1 * c;
	ARR[1][1] = mult * a;
}
