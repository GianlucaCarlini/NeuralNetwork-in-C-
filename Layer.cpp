#include "Layer.h"

Layer::Layer(int number){
    this -> number = number;

    for(int i = 0; i < number; i++){
        Neuron n(0.00);
        this -> neurons.push_back(n);
    }
}

void Layer::setVal(int index, double val){
    this -> neurons.at(index).SetVal(val);
}

Matrix Layer::toMatrixVals(){
    Matrix m(1, number);
    for(int i = 0; i < number; i++){
        m.SetVal(0, i, this -> neurons.at(i).GetVal());
    }
    return m;
}


Matrix Layer::toMatrixActivated(){
    Matrix m(1, number);
    for(int i = 0; i < number; i++){
        m.SetVal(0, i, this -> neurons.at(i).GetActivatedVal());
    }
    return m;
}


Matrix Layer::toMatrixDerived(){
    Matrix m(1, number);
    for(int i = 0; i < number; i++){
        m.SetVal(0, i, this -> neurons.at(i).GetDerivedVal());
    }
    return m;
}
