#include "doctest.h"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

TEST_CASE("Unary operators"){
    // init two matrix
    vector<double> arr = {1,0,0,0,1,0,0,0,1};
    Matrix mat1{arr, 3, 3};
    Matrix mat2(arr, 3, 3);

    +mat1;
    CHECK(mat1 == mat2);

    // check the unary - operator
    CHECK(mat1 == mat2);
    mat1 -= 1;    
    CHECK(mat1 != mat2);
    mat2 -= 1;
    CHECK(mat1 == mat2);

}

TEST_CASE("Binary add & sub operators"){

    // init matrix
    vector<double> arr1 = {2, 3, 6, 9};
    vector<double> arr2 = {5, 6, 2, 5};
    vector<double> arr3 = {1,2,3 , 4,5,6 , 6,7,8};
    Matrix mat1{arr1,2,2};
    Matrix mat2{arr2, 2,2};
    Matrix mat3{arr3, 3, 3};

    // addition on 2 matrixes with the same dimensions shouldn't throw 
    CHECK_NOTHROW(mat1+mat2);  

    vector<double> arr1_2 = {7, 9, 8, 14};
    Matrix mat12{arr1_2, 2, 2};
    mat1 += mat2;
    // after the above action, these matrixes ahould be equal
    CHECK(mat1 == mat12);

    // addition on 2 matrixes with different dimensions should throw
    CHECK_THROWS(mat1 + mat3);
    CHECK_THROWS(mat2 + mat3);

    // check that no addition has happend
    CHECK(mat1 == mat12);


    mat12 -= mat2;
    Matrix mat12_2{arr1, 2, 2};
    // should be equal
    CHECK(mat12 == mat12_2);
}

TEST_CASE("Compare operators"){
    // init matrixes
    vector<double> arr1 = {2.2, 3, 6, 9.1};
    vector<double> arr2 = {5, 6.5, -2, 5};
    vector<double> arr3 = {1,2.4,-3 , -4,5,6 , 6,7.5,8};
    vector<double> arr4 = {-7,15,2, 45,-29,8, 0,4,12};
    Matrix mat1{arr1,2,2};
    Matrix mat2{arr2, 2,2};
    Matrix mat3{arr3, 3, 3};
    Matrix mat4{arr4, 3, 3};

    // matrixes with different dimensions shouldn't be comparable
    bool i;
    CHECK_THROWS(i = mat1 > mat3);
    CHECK_THROWS(i = mat2 >= mat3);
    CHECK_THROWS(i = mat1 < mat4);
    CHECK_THROWS(i = mat2 <= mat4);
    CHECK_THROWS(i = mat1 == mat3);
    CHECK_THROWS(i = mat1 != mat3);

    // shouldn't throw, same dimensions
    CHECK_NOTHROW(i = mat1 > mat2);
    CHECK(mat1 > mat2);
    CHECK_NOTHROW(i = mat1 >= mat2);
    CHECK_NOTHROW(i = mat3 < mat4);
    CHECK(mat3 < mat4);
    CHECK(mat3 != mat4);
    CHECK(!(mat1 == mat2));
}

TEST_CASE("Increasing and Decreasing operators"){
    // init matrixes
    vector<double> arr1 = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    vector<double> arr2 = {1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    Matrix mat1{arr1, 4, 4};
    Matrix mat2{arr2, 4, 4};

    // check ++
    ++mat1;
    CHECK(mat1 == mat2);

    
    CHECK(mat1 == mat2++);
    CHECK(mat1 < mat2++);
    CHECK(mat1 <= mat2);
}

TEST_CASE("Multiplication operators"){
    // init matrixes
    vector<double> arr1 = {2.2, 3, 6, 9.1};
    vector<double> arr2 = {5, 6.5, -2, 5};
    vector<double> arr12 = {5, 29.3, 11.8, 84.5};
    vector<double> arr3 = {1,2.4,-3 , -4,5,6 , 6,7.5,8};
    vector<double> arr4 = {-7,15,2, 45,-29,8, 0,4,12};
    Matrix mat1{arr1,2,2};
    Matrix mat2{arr2, 2,2};
    Matrix mat12{arr12, 2,2};
    Matrix mat3{arr3, 3, 3};
    Matrix mat4{arr4, 3, 3};

    CHECK_THROWS(mat1*mat3);    // 2x2 X 3x3 isn't valid
    CHECK_THROWS(mat2*mat4);    // same here

    CHECK(mat1*mat2 == mat12);      // result should be equal to 

    // same dimensions -> should work
    CHECK_NOTHROW(mat1*mat2);
    CHECK_NOTHROW(mat3*mat4);

    CHECK_NOTHROW(mat1*1);
    CHECK(mat3*1 == mat3);

}