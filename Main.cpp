#include "Matrix.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace zich;

int main()
{
    vector<double> vec1 = {1,2,3,4 , 1,2,7,5, 9,3,2,1, 12,9,1,10};
    vector<double> vec2 = {1,2,3,24 , 1,42,7,5, 9,3,2,1, 17,9,1,10};
    Matrix mat1{vec1, 4,4};
    Matrix mat2{vec2, 4,4};
    
    cout << "Matrix 1: \n" << mat1 << endl;
    cout << "Matrix 2: \n" << mat2 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming * operation:~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << mat1*mat2 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming ++Matrix1 prefix operation:~~~~~~~~~" << endl;
    cout << ++mat1 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming --Matrix2 prefix operation:~~~~~~~~~" << endl;
    cout << --mat2 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming Matrix1 + Matrix2 operation:~~~~~~~~" << endl;
    cout << mat2+mat1 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming Matrix1 - Matrix2 operation:~~~~~~~~" << endl;
    cout << mat1-mat2 << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming cin operation:~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Please enter your own Matrix:" << endl;
    cin >> mat1;
    cout << "You've entered this Matrix:" << endl;
    cout << mat1 << endl;

    return 0;
}   