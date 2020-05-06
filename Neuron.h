#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED

#include <iostream>
using namespace std;

class Neuron{

public:

    Neuron(double val);

    void SetVal(double v);

    //our activation function
    // Relu: f(x) = max(0, x)
    void ReLu();

    // derivative of our activation function
    // derivative of Relu: f'(x) = 0 if x < 0, 1 else
    void derived();

    // Getter functions

    double GetVal(){return this -> val;}
    double GetActivatedVal(){return this -> activated_value;}
    double GetDerivedVal(){return this -> derived_value;}

private: // The private section of the neuron will hold the current values of the neuron
    double val;
    double activated_value;
    double derived_value;

};

#endif // NEURON_H_INCLUDED
