#include "Matrix.hpp"
#include <string>

using namespace zich;
using namespace std;

namespace zich{
    
        // unary operators
        Matrix& Matrix::operator+(){return *this;}
        Matrix& Matrix::operator-(){return *this;}

        // binary operators

        Matrix& Matrix::operator+(const Matrix& mat2){return *this;}
        Matrix& Matrix::operator-(const Matrix& mat2){return *this;}
        Matrix& Matrix::operator+=(const Matrix& mat2){return *this;}
        Matrix& Matrix::operator-=(const Matrix& mat2){return *this;}

        // comparisions operators

        bool operator== (const Matrix& c1, const Matrix& c2){return true;}
        bool operator!= (const Matrix& c1, const Matrix& c2){return true;}

        bool operator< (const Matrix& c1, const Matrix& c2){return true;}
        bool operator> (const Matrix& c1, const Matrix& c2){return true;}

        bool operator<= (const Matrix& c1, const Matrix& c2){return true;}
        bool operator>= (const Matrix& c1, const Matrix& c2){return true;}

        // increasing and decreasing operators

        Matrix& Matrix::operator++(){return *this;}
        Matrix& Matrix::operator--(){return *this;}

        // multipication operators

        Matrix operator*(const Matrix& mat, int value){
            return Matrix{{0,0,0,0}, 2,2};
        }
        Matrix operator*(int value, const Matrix& mat){
            return Matrix{{0,0,0,0}, 2,2};
        }
        Matrix Matrix::operator*=(const int& mul){return *this;}
        Matrix Matrix::operator*(const Matrix& mat2){
            return Matrix{{0,0,0,0}, 2,2};;
        }
        Matrix Matrix::operator*=(const Matrix& mat2){
            return Matrix{{0,0,0,0}, 2,2};
        }

        // output and input operators

        ostream &operator<<( ostream &output, const Matrix& mat ){
            return output;
        }
        istream &operator>>(istream &input, Matrix& mat){
            return input;
        }
}