#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "Neuron.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;

class Layer{
public:
    Layer(int number);

    void setVal(int index, double val);

    // We need some functions that can turn the actual neuron layer into an 1xn matrix, where n is the number of neurons
    Matrix toMatrixVals();
    Matrix toMatrixActivated();
    Matrix toMatrixDerived();
private:
    int number;

    vector<Neuron > neurons;


};


#endif // LAYER_H_INCLUDED
