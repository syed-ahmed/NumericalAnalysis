#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int i;
    cout << "Please enter an integer number: ";
    cin >> i;
    cout << "The value you entered is " << i << endl;
    cout << "Now we are going to approximate the number pi using inverse trignometry" << endl;
    cout << "Printing at 9 significant digits..."  << endl;
    printf("PI = %.8f\n", 6.0*asin(0.5));
    return 0;
}