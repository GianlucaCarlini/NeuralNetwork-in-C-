#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class Matrix{

public:
    Matrix(int nRows, int nCols);

    Matrix *transpose();

    double makeRandomNumber();
    void SetVal(int r, int c, double v);
    double GetVal(int r, int c);

    void PrintMatrix();

    int getnRows(){return this -> nRows;}
    int getnCols(){return this -> nCols;}

private:
    int nRows;
    int nCols;

    vector< vector<double> > values;

};

#endif // MATRIX_H_INCLUDED
