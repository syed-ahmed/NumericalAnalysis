#include "math.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// No need to pass in variables
int main()
{

    // Demonstrating round off error
    // Result loses the floating point
    int num1 = 5;
    int num2 = 2;
    float result;
    result = num1 / num2;
    cout << "Floating point disappears!\n";
    cout << result << "\n";

    float num3 = 5;
    float num4 = 2;
    result = num3 / num4;
    cout << "Floating point is preserved!\n";
    cout << result << "\n";
}