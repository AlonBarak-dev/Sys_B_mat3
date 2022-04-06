#ifndef MATRIX_INCLUDED
#define MATRIX_INCLUDED

#include <string>
#include <vector>
#include <iostream>

namespace zich{

    class Matrix{

        private:
            int rows;
            int cols;
            std::vector<double> matrix;

        public:
            
            // constructor
            Matrix(){}
            Matrix(std::vector<double> mat, int rows, int cols){
                // throw error if the size of the vector isn't matching the rows and columns size
                if (rows*cols != mat.size() || rows < 0 || cols < 0)
                {
                    throw std::runtime_error("Wrong size values!");
                }
                
                this->rows = rows;
                this->cols = cols;
                this->matrix = mat;
            }

            // unary operators
            Matrix& operator+();    // done
            Matrix operator-();     // done

            // binary operators

            Matrix operator+(const Matrix& mat2);       // done
            Matrix operator-(const Matrix& mat2);       // done
            Matrix& operator+=(const Matrix& mat2);     // done
            Matrix& operator-=(const Matrix& mat2);     // done
            Matrix& operator+=(const double num);       // done
            Matrix& operator-=(const double num);       // done
            Matrix operator+(const double num);         // done
            friend Matrix operator+(const double num, const Matrix& mat);       // done
            friend Matrix operator-(const double num, const Matrix& mat);       // done
            Matrix operator-(const double num);         // done
            // compare operators

            friend bool operator== (const Matrix& c1, const Matrix& c2);
            friend bool operator!= (const Matrix& c1, const Matrix& c2);

            friend bool operator< (const Matrix& c1, const Matrix& c2);
            friend bool operator> (const Matrix& c1, const Matrix& c2);

            friend bool operator<= (const Matrix& c1, const Matrix& c2);
            friend bool operator>= (const Matrix& c1, const Matrix& c2);

            // increasing and decreasing operators

            Matrix& operator++();
            Matrix& operator++(int);
            Matrix& operator--();
            Matrix& operator--(int);

            // multiplication operators

            friend Matrix operator*(const Matrix& mat, int value);
            friend Matrix operator*(int value, const Matrix& mat);
            Matrix operator*=(const int& mul);
            Matrix operator*(const Matrix& mat2);
            Matrix operator*=(const Matrix& mat2);

            // output and input operators

            friend std::ostream &operator<<(std::ostream &output, const Matrix& mat );
            friend std::istream &operator>>(std::istream &input, Matrix& mat);


        
    };




}



#endif