#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Layer.h"

class Network{

public:
    Network(vector<int> structure);

    void setInputs(vector<double> input);
    void setTarget(vector<double> x){target = x;};

    void Summary();

    Matrix GetOutput();

    void FeedForward();
    void BackPropagation(double LearningRate);

    double getLoss(){return this -> Loss;};

    void SetError();

private:

    vector<int> structure;
    int structureSize;
    vector<Layer > layers;
    vector<Matrix> weights;
    vector<Matrix> gradients;
    vector<double> input;
    vector<double> target;
    vector<double> historicalErrors;
    vector<double> outputErrors;
    double Loss;
};


#endif // NETWORK_H_INCLUDED
