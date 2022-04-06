#include "Matrix.hpp"
#include <string>

using namespace zich;
using namespace std;

namespace zich{

        // unary operators
        Matrix& Matrix::operator+(){
            
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the negative values of this.matrix
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                arr.push_back(1 * (this->matrix.at(i)));
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, this->rows, this->cols};
            return new_matrix;
        }

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

        Matrix Matrix::operator+(const Matrix& mat2){

            // create a new object of type Matrix 
            Matrix new_matrix{this->matrix, this->rows, this->cols};
            // operate += on the new matrix
            new_matrix += mat2;
            return new_matrix;
        }
        
        
        Matrix Matrix::operator-(const Matrix& mat2){
            // create a new object of type Matrix 
            Matrix new_matrix{this->matrix, this->rows, this->cols};
            // operate += on the new matrix
            new_matrix -= mat2;
            return new_matrix;
        }

        Matrix& Matrix::operator+=(const Matrix& mat2){
            if (this->cols != mat2.cols || this->rows != mat2.rows)
            {
                // the matrixes are not from the same dimensions
                throw runtime_error("operator + is only valid for same dimensions matrixes");
            }
            // initialize the vector with the 
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                this->matrix.at(i) += mat2.matrix.at(i);
            }
            
            return *this;
        }
        Matrix& Matrix::operator-=(const Matrix& mat2){
            if (this->cols != mat2.cols || this->rows != mat2.rows)
            {
                // the matrixes are not from the same dimensions
                throw runtime_error("operator + is only valid for same dimensions matrixes");
            }
            // initialize the vector with the 
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                this->matrix.at(i) -= mat2.matrix.at(i);
            }
            return *this;
        }

        Matrix Matrix::operator+(const double num){
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the 
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                arr.push_back(num + (this->matrix.at(i)));
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, this->rows, this->cols};
            return new_matrix;
        }

        Matrix Matrix::operator-(const double num){
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the negative values of this.matrix
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                arr.push_back((this->matrix.at(i)) - num);
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, this->rows, this->cols};
            return new_matrix;
        }

        Matrix& Matrix::operator+=(const double num){
             // initialize the vector with the 
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                this->matrix.at(i) += num;      // adds to each element 
            }
            return *this;
        }

        Matrix& Matrix::operator-=(const double num){
             // initialize the vector with the 
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                this->matrix.at(i) -= num;      // adds to each element 
            }
            return *this;
        }


        Matrix operator+(const double num, const Matrix& mat){
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the 
            for (size_t i = 0; i < mat.matrix.size(); i++)
            {
                arr.push_back(num + (mat.matrix.at(i)));
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, mat.rows, mat.cols};
            return new_matrix;
        }

        Matrix operator-(const double num, const Matrix& mat){
            vector<double> arr;     // the vector of the new matrix
            // initialize the vector with the 
            for (size_t i = 0; i < mat.matrix.size(); i++)
            {
                arr.push_back(num - (mat.matrix.at(i)));
            }
            // create a new object of type Matrix and return it
            Matrix new_matrix{arr, mat.rows, mat.cols};
            return new_matrix;
        }

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