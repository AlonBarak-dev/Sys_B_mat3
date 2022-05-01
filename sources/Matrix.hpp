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
            
            // constructor & destructor
            Matrix(const std::vector<double> &mat, int rows, int cols);
            ~Matrix();

            // unary operators
            Matrix operator+();    // done
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

            friend bool operator== (const Matrix& c1, const Matrix& c2);    //done
            friend bool operator!= (const Matrix& c1, const Matrix& c2);    //done

            friend bool operator< (const Matrix& c1, const Matrix& c2);     //done
            friend bool operator> (const Matrix& c1, const Matrix& c2);     //done

            friend bool operator<= (const Matrix& c1, const Matrix& c2);    //done
            friend bool operator>= (const Matrix& c1, const Matrix& c2);    //done

            // increasing and decreasing operators

            Matrix& operator++();       //done
            Matrix operator++(int);     //done
            Matrix& operator--();       //done
            Matrix operator--(int);     //done

            // multiplication operators

            Matrix operator*(const double& value);  // done
            friend Matrix operator*(const double& value, const Matrix& mat);   // done
            Matrix&operator*=(const double& mul);       // done
            Matrix& operator*=(const Matrix& mat2);     // done
            Matrix operator*(const Matrix& mat2) const;       // done

            // output and input operators

            friend std::ostream &operator<<(std::ostream &output, const Matrix& mat );  // done
            friend std::istream &operator>>(std::istream &input, Matrix& mat);

            // auxiliaries method
            friend double sum(const Matrix& mat);   //done
            friend double row_col_mul(const Matrix& mat1, const Matrix& mat2, int row, int col);        // done
        
    };




}



#endif