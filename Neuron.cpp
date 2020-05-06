#include "Neuron.h"

//Constructor

Neuron::Neuron(double val){
    this -> val = val;
    ReLu();
    derived();
}

// Function to set the value of the neuron

void Neuron::SetVal(double val){
    this -> val = val;
    ReLu();
    derived();
}

// Activation function (ReLu)

void Neuron::ReLu(){

    if ((this->val) > 0){
        this-> activated_value = this->val;
        }

    else{
        this-> activated_value = 0;
        }
}

// Derivative of the activation function

void Neuron::derived(){

    if ((this-> val >= 0)){
        this-> derived_value = 1;
        }
    else{this-> derived_value = 0;}
}
