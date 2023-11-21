//  matrix.h



#ifndef lab9_Dynamic_Matrix__matrix__
#define lab9_Dynamic_Matrix__matrix__
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

class Matrix{
public:
    Matrix(int m, int n);
    // REQUIRES: m and n refer to the number of rows and columns in a numeric
    //           matrix.
    // PROMISES: - assigns matrixM, to a dynamically allocated array of m
    //            double-pointer, where each pointer points to a dynamically
    //            allocated array of n doubles.
    //          - Assigns sum_rowsM to a dynamically allocated array of m doubles
    //          - Assigns sum_colsM to a dynamically allocated array of n doubles
    //          - initializes rowsM and colsM with the values of m and n
    //            respectively
    
    // Default ctor
    Matrix():matrixM(NULL), sum_rowsM(NULL), sum_colsM(NULL), rowsM(0), colsM(0)
    {}
    
    ~Matrix();
    //PROMISES: - calls helper function destroy
    
    Matrix& operator=(const Matrix& rhs);
    
    // copy ctor
    Matrix(const Matrix& source);
    
    int get_rows() const {return rowsM;}
    
    int get_cols() const {return colsM;}
    
    double& at(int r, int c) {return matrixM[r][c];}
    // PROMISES: - returns the value in the r_th row and c_th column of matrixM
    
    const double& at(int r, int c)const {return matrixM[r][c];}
    // PROMISES: - returns the value in the r_th row and c_th column of matrixM
    
    double get_sum_col(int i) const;
    // REQUIRES: i >=0 and i < colsM
    // PROMISES: - returns sum of the values in the i_th column
    double get_sum_row(int i) const;
    // REQUIRES: i >=0 and i < rowsM
    //PROMISES: - returns sum of the values in the i_th row
    void sum_of_rows()const;
    // PROMISES: calculate sum of values in each row of the matrix, storing them
    //           into the elements of sum_rowsM array, already created by the a
    //           ctor.
    
    void sum_of_cols()const;
    // PROMISES: calculate sum of values in each column of the matrix, storing
    //           them into the elements of the sum_colsM array, already create by
    //           a ctro.
    
private:
    double ** matrixM;   // points to an array of double-pointers on the heap
    double* sum_rowsM;   // points to an array of doubles on the heap
    double* sum_colsM;   // points to an array of doubles on the heap
    int rowsM;           // number of rows of matrix
    int colsM;           // number of columns of matrix
    
    void copy(const Matrix& souce);
    // PROMISES: makes this matrix a copy of source
    
    void destroy();
    //PROMISES: - deallocats memory which is dynamically allocated
    //            for each pointer in each element matrixM.
    //            Then deallocates memory which is dynamiclaly allocated for
    //            matrixM. Also deallocates memories allocated for arrays
    //            sum_colsM, and sum_rowsM.
};

#endif /* defined(lab9_Dynamic_Matrix__matrixM__) */





//   matrix.cpp

//
#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
    double sum;
    for(int i = 0; i < rowsM; i++){
        sum = 0;
        for(int j = 0; j < colsM; j++){
            sum += matrixM[i][j];
        }
        sum_rowsM[i] = sum;
    }
}

void Matrix::sum_of_cols()const
{
    double sum;
    for(int i = 0; i < colsM; i++){
        sum = 0;
        for(int j = 0; j < rowsM; j++){
            sum += matrixM[j][i];
        }
        sum_colsM[i] = sum;
    }
    
}

void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM;
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    for(int i = 0; i < rowsM; i++)
        for(int j = 0; j < colsM; j++)
            matrixM[i][j] = source.matrixM[i][j];
    
    sum_rowsM = source.sum_rowsM;
    sum_colsM = source.sum_colsM;
}


    

void Matrix::destroy()
{
    delete *matrixM;
    delete matrixM;
    sum_rowsM = NULL;
    sum_colsM = NULL;
}






//  lab9ExE.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//#include "matrix.h"

void populate_matrix(Matrix& m, int seed);
// PROMISES: populates the elements of matrix m with arbitrary double numbers.
//           using seed to produce different values.

bool not_all_digits(const char* str);
// REQUIRES: returns true if any charactres in str is not a digit

void print(const Matrix& m);
// PROMISES: prints the values of the matrix in tabular format.

void print_with_sum(const Matrix& m);
// PROMISES: prints the matrix in tabular format, plus sum of its rows and columns

int main(int argc, const char * argv[]) {
    int row, col;
    
    if (argc < 3){
        cout << "\nError: too few arguments";
        exit(1);
    }
    
    if(not_all_digits(argv[1])){
       cout << " The arguments of " << argv[0] << " must be digits.";
       exit(1);
    }
    
    if(not_all_digits(argv[2])){
        cout << " The arguments of " << argv[0] << " must be digits.";
        exit(1);
    }
  
    // library function atoi converts a string of digits to integer number
    row = atoi(argv[1]);
    col = atoi(argv[2]);
    
    
    Matrix m1(row, col);
    populate_matrix(m1, 5);
    
    cout << "\n\nThe values in matrix m1 are:\n\n";
    print(m1);
    
#if 1
    Matrix m2 (4, 6);
    populate_matrix(m2, 6);

    cout << "\n\nThe values in matrix m2 are: \n";
    print (m2);
    
    m2.sum_of_rows();
    m2.sum_of_cols();
    m1 = m2;
    
    m2.at(0, 0)=5;
    m2.at(1, 1)=15;
    m2.at(2, 2)=25;

    cout << "\n\nThe new values in matrix m1 and sum of its rows and columns are\n";
    print_with_sum(m1);
    
    m2.sum_of_rows();
    m2.sum_of_cols();
    
    Matrix m3 = m2;
    
    m2.at(0, 0)= -5;
    m2.at(1, 1)= -15;
    m2.at(2, 2)= -25;

    cout << "\n\nThe values in matrix m3 and sum of its rows and columns are:\n";
    print_with_sum(m3);
    
    m2.sum_of_rows();
    m2.sum_of_cols();
   cout << "\nThe new values in matrix m2 are:\n";
   print_with_sum(m2);
   
   cout << "\n\nThe values in matrix m3 and sum of it rows and columns are still the same:\n";
   print_with_sum(m3);
#endif
    
    return 0;
}

void populate_matrix(Matrix& m, int seed)
{
    cout << fixed << setprecision(1);
    for(int i= 0; i < m.get_rows(); i++)
        for(int j=m.get_cols()-1; j>=0; j--)
            m.at(i, j) = (seed + (j+i+1) +(j+1))/3.0;
}

void print(const Matrix& m)
{
    if(m.get_rows() == 0 && m.get_cols() == 0){
        cout << "Matrix is empty." << endl;
        return;
    }
    
    for (int i=0;i< m.get_rows(); i++){
        for(int j = 0; j < m.get_cols(); j++)
            cout << " " << setw(5) <<  m.at(i, j);
        cout <<  endl;
    }
}


void print_with_sum(const Matrix& m)
{
    if(m.get_rows() == 0 && m.get_cols() == 0){
        cout << endl << "Your matrix is empty." << endl;
        return;
    }

    for (int i=0;i< m.get_rows(); i++){
        for(int j = 0; j < m.get_cols(); j++)
            cout << " " << setw(5) <<  m.at(i, j);
        cout << " |" << setw(5) << m.get_sum_row(i) << endl;
    }
    
    cout << setw(5) << ' ';
    for(int j =0; j < m.get_cols(); j++)
        cout<< "------"  ;
    cout << endl;
    
    for(int j =0; j < m.get_cols(); j++)
        cout<< " " << setw(5) << m.get_sum_col(j) ;
    cout << endl;
}

bool not_all_digits(const char* str){
    for(int i=0; str[i] != '\0'; i++)
        if(!isdigit(str[i]))
            return true;
    return false;
}
