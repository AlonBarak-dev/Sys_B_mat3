#include "Matrix.hpp"

using namespace zich;
using namespace std;

Matrix parse(string const& str, char delim);

namespace zich{

    // CTOR && DCTOR

    Matrix::Matrix(const std::vector<double> &mat, int rows, int cols){
        // throw error if the size of the vector isn't matching the rows and columns size
        if (rows*cols != mat.size() || rows < 0 || cols < 0)
        {
            throw std::runtime_error("Wrong size values!");
        }
        
        this->rows = rows;
        this->cols = cols;
        this->matrix = mat;
    }

    Matrix::~Matrix(){}

    // unary operators
    Matrix Matrix::operator+(){
        
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
            if (this->matrix.at(i) != 0)
            {
                arr.push_back(-1 * (this->matrix.at(i)));
            }
            else{
                arr.push_back(0);
            }
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

    double sum(const Matrix& mat){
        // auxiliary method that claculate the sum of a matrix
        double sum = 0;
        for (size_t i = 0; i < mat.matrix.size(); i++)
        {
            sum += mat.matrix.at(i);
        }
        return sum;
    }

    bool operator== (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator == is only valid for same dimensions matrixes");
        }
        for(size_t i = 0; i < mat1.matrix.size();i++){
            if (mat1.matrix.at(i) != mat2.matrix.at(i))
            {
                return false;
            }
        }
        return true;
    }
    bool operator!= (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator != is only valid for same dimensions matrixes");
        }
        return !(mat1 == mat2);
    }

    bool operator< (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator < is only valid for same dimensions matrixes");
        }
        return sum(mat1) < sum(mat2);
    }
    bool operator> (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator > is only valid for same dimensions matrixes");
        }
        return sum(mat1) > sum(mat2);
    }

    bool operator<= (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator <= is only valid for same dimensions matrixes");
        }
        return sum(mat1) < sum(mat2) || mat1 == mat2;
    }
    bool operator>= (const Matrix& mat1, const Matrix& mat2){
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows)
        {
            // the matrixes are not from the same dimensions
            throw runtime_error("operator >= is only valid for same dimensions matrixes");
        }
        return sum(mat1) > sum(mat2) || mat1 == mat2;
    }

    // increasing and decreasing operators

    Matrix& Matrix::operator++(){   // prefix
        return (*this += 1);
    }

    Matrix Matrix::operator++(int){     // postfix
        Matrix new_matrix = *this;   //copy
        ++*this;
        return new_matrix;  // return the copy
    }

    Matrix Matrix::operator--(int){     // postfix
        Matrix new_matrix = *this;  // copy
        --*this;
        return new_matrix;  //return the copy
    }

    Matrix& Matrix::operator--(){      // prefix
        return (*this -= 1);
    }

    // multipication operators

    double row_col_mul(const Matrix& mat1, const Matrix& mat2, int row, int col){
        // given two matrixes, row number and column number:
        // multiply each element in mat1 by each element in mat2 and sum the result
        // return the sum

        double sum = 0;
        size_t index = 0;

        for (size_t i = 0; i < mat1.cols; i++)
        {
            sum += mat1.matrix.at(i + size_t(mat1.cols*row)) * mat2.matrix.at(size_t(col) + size_t(mat2.cols)*i);
        }
        return sum;
    }

    Matrix Matrix::operator*(const double& value){  
        // matrix * value
        Matrix new_mat{this->matrix, this->rows, this->cols};   // create new matrix
        
        // init the new matrix with the values of this->matrix multiply by  value
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            new_mat.matrix.at(i) = this->matrix.at(i) * value;
        }
        return new_mat;
    }


    Matrix operator*(const double& value, const Matrix& mat){
        // value * matrix
        Matrix new_mat{mat.matrix, mat.rows, mat.cols};   // create new matrix

        // init the new matrix with the values of this->matrix multiply by  value
        for (size_t i = 0; i < mat.matrix.size(); i++)
        {
            new_mat.matrix.at(i) = mat.matrix.at(i) * value;
        }
        return new_mat;
    }
    
    
    Matrix& Matrix::operator*=(const double& mul){
        // matrix *= value
        *this = *this * mul;
        return *this;
    }
    
    Matrix& Matrix::operator*=(const Matrix& mat2){
        // matrix *= matrix
        *this = *this * mat2;
        return *this;
    }
    
    
    Matrix Matrix::operator*(const Matrix& mat2) const{
        // matrix * matrix

        if(this->cols != mat2.rows){    // dimensions check:
            throw runtime_error("Matrices with different dimensions cannot be multiply by each other!");
        }

        vector<double> vec;
        // loop over the rows of this matrix
        for (size_t row = 0; row < this->rows; row++)
        {
            // loop over mat2 columns
            for (size_t col = 0; col < mat2.cols; col++)
            {
                // insert the sum of multipication into vec
                vec.push_back(row_col_mul(*this, mat2, (int)row, (int)col));
            }
        }
        // create a new Matrix from vec
        Matrix new_mat{vec, this->rows, mat2.cols};
        return new_mat;
    }
    

    // output and input operators

    ostream& operator<<(ostream &output, const Matrix& mat ){

        size_t index = 0;
        for (size_t i = 0; i < mat.rows; i++)
        {
            output << "[";
            for (size_t j = 0; j < mat.cols; j++)
            {
                output << mat.matrix[index];
                if (j != mat.cols-1)
                {
                    output << " ";
                }
                
                index++;
            }
            output << "]";
            if (i != mat.rows -1)
            {
                output << "\n";
            }
        }
        return output;
    }

    istream &operator>>(istream &input, Matrix& mat){
        
        string str;
        getline(input, str);
        mat = parse(str, ',');
        return input;
    }
}

Matrix parse(string const& str, char delim){

        vector<string> vec;
        vector<string> tmp;
        vector<double> ret_vector;
        int rows = 0;
        int cols = 0;
        size_t start = 0;
        size_t end = 0;

        if (str.at(0) != '[' || str.at(str.size()-1) != ']')
        {
            // first char should be '[', throw exception,
            // last char should be ']', throw exception
            throw runtime_error("Input isn't valid!");
        }
        

        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            vec.push_back(str.substr(start, end - start));
            rows++;
        }

        for(size_t i = 0; i < vec.size(); i++){
            if(i == 0){
                // first str have different validations check:
                if (vec.at(i).at(0) != '[' || vec.at(i).at(vec.at(i).size()-1) != ']')
                {
                    // first char should be '[', throw exception,
                    // last char should be ']', throw exception
                    throw runtime_error("Input isn't valid!");
                }
                // delete the uneeded chars from ths string
                vec.at(i).erase(0,1);
                vec.at(i).erase(vec.at(i).size()-1,vec.at(i).size());
            }
            else{
                if (vec.at(i).at(0) != ' ' || vec.at(i).at(1) != '['  || vec.at(i).at(vec.at(i).size()-1) != ']')
                {
                    // first char should be '[', throw exception,
                    // last char should be ']', throw exception
                    throw runtime_error("Input isn't valid!");
                }
                // delete the uneeded chars from ths string
                vec.at(i).erase(0,2);
                vec.at(i).erase(vec.at(i).size()-1,vec.at(i).size());
            }
            // split the string into vector base on spaces -> valid input should result in vector of "doubles"
            end = 0;
            delim = ' ';
            tmp.clear();
            while ((start = vec.at(i).find_first_not_of(delim, end)) != std::string::npos)
            {
                end = vec.at(i).find(delim, start);
                tmp.push_back(vec.at(i).substr(start, end - start));
            }
            cols = tmp.size();
            for (string const& s: tmp)
            {
                // check if each double is seperated with exactly one " "
                try{
                    ret_vector.push_back(stod(s));
                }
                catch(exception e){
                    throw runtime_error("input is not valid!");
                }
            }
        }

        return zich::Matrix{ret_vector, rows, cols};
    }