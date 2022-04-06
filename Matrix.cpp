#include "Matrix.hpp"
#include <string>

using namespace zich;
using namespace std;

namespace zich{

        // unary operators
        Matrix& Matrix::operator+(){return *this;}

        Matrix Matrix::operator-(){
            
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the negative values of this.matrix
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                arr.push_back(-1 * (this->matrix.at(i)));
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, this->rows, this->cols};
            return new_matrix;
        }

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

        ostream& operator<<(ostream &output, const Matrix& mat ){

            size_t index = 0;
            cout << mat.matrix.size() << " | " << mat.matrix[2] << endl;
            for (size_t i = 0; i < mat.rows; i++)
            {
                output << "[ ";
                for (size_t j = 0; j < mat.cols; j++)
                {
                    output << mat.matrix[index] << " ";
                    index++;
                }
                output << "]\n";
            }
            return output;
        }
        istream &operator>>(istream &input, Matrix& mat){
            return input;
        }
}