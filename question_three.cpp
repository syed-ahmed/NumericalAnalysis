#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3f A;
   A << 1, 2, 1,
        2, 1, 0,
        -1, 1, 2;
   cout << "Here is the matrix A:\n" << A << endl;
   FullPivLU<Matrix3f> lu(A);
   if (!lu.isInvertible()){
       cout << "Matrix is not invertible." << std::endl;
   } else {
       cout << "The inverse of A is:\n" << lu.inverse() << endl;
   }
}