#include <iostream>
#include <math.h>

using namespace std;

int CalculateFactorial(int input_number)
{
    int result;
    if (input_number == 0 || input_number == 1)
    {
        return 1;
    }
    result = CalculateFactorial(input_number - 1) * input_number;
    return result;
}

int CalculateCombination(int n, int r)
{
    int result;
    if (n >= 0 && r >= 0)
    {
        result = CalculateFactorial(n) / (CalculateFactorial(r) * CalculateFactorial(n - r));
    }
    else
    {
        result = 0;
    }
    return result;
}

float CalculatePi(int num_iterations)
{
    float pi_value = 0;
    for (int i = 0; i < num_iterations; i++)
    {
        pi_value += (3 * CalculateCombination(2 * i, i)) / (pow(16, i) * (2 * i + 1));
    }
    return pi_value;
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    int i;
    cout << "Please enter the number of iterations you want to use to approximate pi: ";
    cin >> i;
    cout << "The value you entered is " << i << endl;
    cout << "Now we are going to approximate the number pi using inverse trignometry" << endl;
    printf("PI = %f\n", CalculatePi(i));
    return 0;
}