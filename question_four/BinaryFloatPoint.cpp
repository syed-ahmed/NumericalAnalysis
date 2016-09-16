#include "math.h"
#include <limits.h>
#include <bitset>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

double fractionalBin(double fraDecimal);
int DoubleToBinary32(double value);

int main() {
	double a = 10.5;
	double b, c;

	//print decimal values
	b = 1.0/3.0;
	c = 22.0 / 7.0;
	cout.precision(10);
	cout << "Decimal: \n";
	cout << "a = " << a << "\n" << "b = " << b << "\n" << "c = " << c << "\n" << endl;

	//calculate values in bianary
	double a_bin = fractionalBin(a);
	double b_bin = fractionalBin(b);
	double c_bin = fractionalBin(c);
	cout << "Binary: " << endl;
	cout << "a = " << a_bin << "\n" << "b = " << b_bin << "\n" << "c = " << c_bin << "\n" << endl;

	//calculate 64 bit floating point
	int a_float = DoubleToBinary32(a);
	int b_float = DoubleToBinary32(b);
	int c_float = DoubleToBinary32(c);
	cout << "64-bit Floating Point Notation: " << endl;
	cout << "a = " << a_float << "\n" << "b = " << b_float << "\n" << "c = " << c_float << "\n" << endl;
	

}

double fractionalBin(double fraDecimal){
	double fraBinary, bFractional = 0.0, dFractional, fraFactor = 0.1;
	long int dIntegral, bIntegral = 0;
	long int intFactor = 1, remainder, temp, i;
	dIntegral = fraDecimal;
	dFractional = fraDecimal - dIntegral;

	while (dIntegral != 0){
		remainder = dIntegral % 2;
		bIntegral = bIntegral + remainder*intFactor;
		dIntegral = dIntegral / 2;
		intFactor = intFactor * 10;
	}

	for (i = 1; i <= 12; i++){

		dFractional = dFractional * 2;
		temp = dFractional;

		bFractional = bFractional + fraFactor* temp;
		if (temp == 1)
			dFractional = dFractional - temp;

		fraFactor = fraFactor / 10;
	}

	fraBinary = bIntegral + bFractional;
	return fraBinary;
}

int DoubleToBinary32(double value)
{
	int minus = 0, integer, exponent = 127, fraction = 0, i, result;

	if (value < 0) { minus = 0x80000000; value = -value; }
	integer = floor(value);
	value -= integer;
	for (i = 22; i >= 0; i--)
	{
		value += value;
		fraction += floor(value) * pow(2, i);
		value -= floor(value);
	}
	while ((integer != 1) && (exponent > 0) && (exponent < 255))
	{
		if (integer > 1)
		{
			fraction = (integer & 1) << 22 + fraction >> 1;
			integer = integer >> 1;
			exponent++;
		}
		else
		{
			integer = (fraction & 0x400000) >> 22;
			fraction = (fraction & 0x3FFFFF) << 1;
			value += value;
			fraction += floor(value);
			value -= floor(value);
			exponent--;
		}
	}
	result = minus + exponent << 23 + fraction;
	return(result);
}