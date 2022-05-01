#include "Matrix.hpp"


using namespace std;
using namespace zich;

int main()
{

    vector<double> mat1;
    vector<double> mat2;

    int m1_rows, m1_cols, m2_rows, m2_cols;
    double temp;

    while(true){
        try{
            int operation;
            cout << "Please choose an operation: \n "<< 
            "1. Mat1 unary + \n" << 
            "2. Mat1 unary - \n" <<
            "3. Mat1 + Mat2 \n" << 
            "4. Mat1 - Mat2 \n"<<
            "5. Mat2 - Mat1 \n" <<
            "6. Mat1 + num \n" << 
            "7. Mat2 + num \n"<<
            "8. Mat1 - num \n"<<
            "9. Mat2 - num \n"<<
            "10. Mat1 * Mat2 \n"<<
            "11. Mat1 * num \n"<<
            "12. Mat2 * num \n"<<
            "13. Mat1 == Mat2 \n"<<
            "14. Mat1 != Mat2 \n"<<
            "15. Mat1 <= Mat2 \n"<<
            "16. Mat1 >= Mat2 \n"<<
            "17. ++Mat1 \n"<<
            "18. --Mat1 \n"<<
            "19. Mat1<<" << endl;
            cin >> operation;


            cout << "Please enter number of rows for the first Matrix: " << endl;
            cin >> m1_rows;
            cout << "Please enter number of columns for the first Matrix: " << endl;
            cin >> m1_cols;

            cout << "Please enter " << m1_rows * m1_cols << "numbers to initialize the first Matrix" << endl;
            for (size_t i = 0; i < m1_rows*m1_cols; i++)
            {
                cin >> temp;
                mat1.push_back(temp);
            }
            
            cout << "Please enter number of rows for the second Matrix: " << endl;
            cin >> m2_rows;
            cout << "Please enter number of columns for the second Matrix: " << endl;
            cin >> m2_cols;

            cout << "Please enter " << m2_rows * m2_cols << "numbers to initialize the second Matrix" << endl;
            for (size_t i = 0; i < m2_rows*m2_cols; i++)
            {
                cin >> temp;
                mat2.push_back(temp);
            }

            Matrix m1{mat1, m1_rows, m1_cols};
            Matrix m2{mat2, m2_rows, m2_cols};

            switch (operation)
            {
            case 1: // unary plus
                cout << (m1) << "\n Result \n" << (+m1) << endl;
                break;
            case 2: //unary minus
                cout << (m1) << "\n Result \n" << (-m1) << endl;
                break;
            case 3: // mat1 + mat2
                cout << (m1) << "\n + \n" << (m2) << "\n = \n" << (m1+m2) << endl;
                break;
            case 4: // mat1 - mat2
                cout << (m1) << "\n - \n" << (m2) << "\n = \n" << (m1-m2) << endl;
                break;
            case 5: // mat2 - mat1
                cout << (m2) << "\n - \n" << (m1) << "\n = \n" << (m1-m2) << endl;
                break;
            case 6: // mat1 + num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m1 + temp) << endl;
                break;
            case 7: // mat2 + num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m2 + temp) << endl;
                break;
            case 8: // mat1 - num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m1 - temp) << endl;
                break;
            case 9: // mat2 - num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m2 - temp) << endl;
                break;
            case 10:    // mat1 * mat2
                cout << (m1*m2) << endl;
                break;
            case 11:    // mat1 * num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m1 * temp) << endl;
                break;
            case 12:    // mat2 * num
                cout << "Please enter a number" << endl;
                cin >> temp;
                cout << (m2 * temp) << endl;
                break;
            case 13:    // mat1 == mat2
                cout << (m1 == m2) << endl;
                break;
            case 14:    // mat1 != mat2
                cout << (m1 != m2) << endl;
                break;
            case 15:    // mat1 <= mat2
                cout << (m1 <= m2) << endl;
                break;
            case 16:    // mat1 >= mat2
                cout << (m1 >= m2) << endl;
                break;
            case 17:    // mat1++
                cout << (++m1) << endl;
                break;
            case 18:    // mat1--
                cout << (--m1) << endl;
                break;
            case 19:    // << mat1
                cout << (m1) << endl;
                break;

            default:
                cout << "Please choose an operation from the above! ^^" << endl;
                break;
            }
        }
        catch(exception &e){
            cerr << e.what() << endl;
        }
    }    























    // vector<double> vec1 = {1,2,3,4 , 1,2,7,5, 9,3,2,1, 12,9,1,10};
    // vector<double> vec2 = {1,2,3,24 , 1,42,7,5, 9,3,2,1, 17,9,1,10};
    // Matrix mat1{vec1, 4,4};
    // Matrix mat2{vec2, 4,4};
    
    // cout << "Matrix 1: \n" << mat1 << endl;
    // cout << "Matrix 2: \n" << mat2 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming * operation:~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // cout << mat1*mat2 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming ++Matrix1 prefix operation:~~~~~~~~~" << endl;
    // cout << ++mat1 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming --Matrix2 prefix operation:~~~~~~~~~" << endl;
    // cout << --mat2 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming Matrix1 + Matrix2 operation:~~~~~~~~" << endl;
    // cout << mat2+mat1 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming Matrix1 - Matrix2 operation:~~~~~~~~" << endl;
    // cout << mat1-mat2 << endl;

    // cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Preforming cin operation:~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // cout << "Please enter your own Matrix:" << endl;
    // cin >> mat1;
    // cout << "You've entered this Matrix:" << endl;
    // cout << mat1 << endl;

    return 0;
}   