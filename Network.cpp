#include "Network.h"

Network::Network(vector<int> structure){
    this -> structure = structure;
    this -> structureSize = structure.size();

    // We will have a number of layers equal to the length of the netwotk, i.e. len(structure)
    for(int i = 0; i < structureSize; i++){
        //each layer will have a number of neurons equal to structure(i)
        Layer *l = new Layer(structure.at(i));
        this -> layers.push_back(l);
    }

    //The number of weight matrices is equal to the lenght of the network - 1, i.e. len(structure - 1)
    for(int i = 0; i < structureSize -1; i++){
        /*The number of rows of the weight matrices will be the number of neurons in the previous layer,
        while the number of columns will be the number of neurons in the actual layer
        */
        Matrix *m = new Matrix(structure.at(i), structure.at(i+1));
        this -> weights.push_back(m);
    }
}

void Network::setInputs(vector<double> input){
    this -> input = input;

    for(int i = 0; i < input.size(); i++){
        this -> layers.at(0) -> setVal(i, input.at(i));
    }
}

void Network::Summary(){
    cout << "Number of layers:" << structureSize << endl;
    for(int i = 0; i < layers.size(); i++){
        if(i == 0){
                cout << "Input Layer\t |\tNeurons: " << structure.at(i) << endl;
                cout << "Input Values:" << endl;
                Matrix *m = this -> layers.at(i) -> toMatrixVals();
                m -> PrintMatrix();
                }
        else{
                cout << "Layer" << (i) << "     |\t Neurons:" << structure.at(i) << endl;
                cout << "Weights:" << endl;
                weights.at(i - 1) -> PrintMatrix();
        }
    }
}
