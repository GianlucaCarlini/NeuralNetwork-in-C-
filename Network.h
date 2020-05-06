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
    void Summary();
private:

    vector<int> structure;
    int structureSize;
    vector<Layer *> layers;
    vector<Matrix *> weights;
    vector<double> input;
};


#endif // NETWORK_H_INCLUDED
