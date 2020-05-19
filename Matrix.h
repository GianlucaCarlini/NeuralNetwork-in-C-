#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class Matrix{

public:
    Matrix(int nRows, int nCols);
    Matrix(const Matrix &Copy);

    Matrix transpose();

    double makeRandomNumber();
    void SetVal(int r, int c, double v);
    double GetVal(int r, int c);

    void PrintMatrix();

    int getnRows() const {return this -> nRows;}
    int getnCols() const {return this -> nCols;}

    Matrix operator*(const Matrix &Right);
    Matrix operator-(const Matrix &Right);
    Matrix operator*(const double &Right);

private:
    int nRows;
    int nCols;

    vector< vector<double> > values;

};

#endif // MATRIX_H_INCLUDED
