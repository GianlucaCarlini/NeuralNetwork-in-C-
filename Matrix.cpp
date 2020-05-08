#include "Matrix.h"
#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <assert.h>
using namespace std;

//Constructor
Matrix::Matrix(int nRows, int nCols){
    this -> nRows = nRows;
    this -> nCols = nCols;

    int r = rand();
    int seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(r + seed);
    uniform_real_distribution<> dis(0, 1);

    for(int i = 0; i < nRows; i++){
        vector<double> ColValues;
        for(int j = 0; j < nCols; j++){
            ColValues.push_back(dis(gen));
        }
        this -> values.push_back(ColValues);
    }

}

//Copy constructor
Matrix::Matrix(const Matrix &Copy){
    values = Copy.values;
    nRows = Copy.getnRows();
    nCols = Copy.getnCols();
}

void Matrix::SetVal(int r, int c, double v){
    this -> values.at(r).at(c) = v;
}

double Matrix::GetVal(int r, int c){
    return this -> values.at(r).at(c);
}

Matrix Matrix::transpose(){
    Matrix m(this -> nCols, this -> nRows); //The number of rows is now the number of columns and vice-versa
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m.SetVal(j, i, this -> GetVal(i, j));
        }
    }

    return m;

}


void Matrix::PrintMatrix(){
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            cout << this -> values.at(i).at(j) << "\t";
        }
        cout << endl;
    }

}

Matrix Matrix::operator*(const Matrix &Right){
    if(nCols != Right.getnRows()){
        cerr << "Number of columns of the left matrix must be equal to the number of rows of the right matrix" << endl;
        assert(false);
    }

    Matrix temp(nRows, Right.getnCols());

    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < Right.getnCols(); j++){
            double v = 0;
            for(int k = 0; k < Right.getnRows(); k++){
                v += (values.at(i).at(k) * Right.values.at(k).at(j));
            }
            temp.values.at(i).at(j) = v;
        }
    }
    return temp;
}
