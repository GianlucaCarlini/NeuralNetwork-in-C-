#include "Network.h"
#include <vector>
#include <cmath>

Network::Network(vector<int> structure){
    this -> structure = structure;
    this -> structureSize = structure.size();

    // We will have a number of layers equal to the length of the netwotk, i.e. len(structure)
    for(int i = 0; i < structureSize; i++){
        //each layer will have a number of neurons equal to structure(i)
        Layer l(structure.at(i));
        this -> layers.push_back(l);
    }

    //The number of weight matrices is equal to the lenght of the network - 1, i.e. len(structure - 1)
    for(int i = 0; i < structureSize -1; i++){
        /*The number of rows of the weight matrices will be the number of neurons in the previous layer,
        while the number of columns will be the number of neurons in the actual layer
        */
        Matrix m(structure.at(i), structure.at(i+1));
        this -> weights.push_back(m);
    }
    for(int i = 0; i < layers.at(structureSize -1).getNeurons().size(); i++){
        outputErrors.push_back(0);
    }
}

void Network::setInputs(vector<double> input){
    this -> input = input;

    for(int i = 0; i < input.size(); i++){
        this -> layers.at(0).setVal(i, input.at(i));
    }
}

Matrix Network::GetOutput(){
    Matrix m = layers.at(structureSize - 1).toMatrixVals();
    return m;
}

void Network::Summary(){
    cout << "Number of layers:" << structureSize << endl;
    for(int i = 0; i < layers.size(); i++){
        if(i == 0){
                cout << "Input Layer\t |\tNeurons: " << structure.at(i) << endl << endl;
                cout << "Input Values:" << endl;
                Matrix m = this -> layers.at(i).toMatrixVals();
                m.PrintMatrix();
                cout << endl;
                }
        else{
                cout << "Layer" << (i) << "     |\t Neurons: " << structure.at(i) << endl << endl;
                cout << "Weights: \n" << endl;
                weights.at(i - 1).PrintMatrix();
                cout << endl;
        }
    }
}

void Network::FeedForward(){
    for(int i = 0; i < layers.size() - 1; i++){  //Looping through layers. The last one is the output, that's why the -1
        Matrix a = layers.at(i).toMatrixVals();
        if(i != 0){a = layers.at(i).toMatrixActivated();}

        Matrix b = weights.at(i);

        Matrix c = a * b;

        for(int col = 0; col < c.getnCols(); col ++ ){
                layers.at(i+1).setVal(col, c.GetVal(0, col));
        }
    }
}

void Network::SetError(){
    int OutputLayerIndex = layers.size() - 1;

    if(target.size() == 0){
        cerr << "There is no target for the Network";
        assert(false);
    }
    if(target.size() != layers.at(OutputLayerIndex).getNeurons().size()){
        cerr << "Target size must be equal to output size";
        assert(false);
    }

    Loss = 0.0;
    Matrix m = GetOutput();

    for(int i = 0; i < target.size(); ++i){
        double temp = (m.GetVal(0,i) - target.at(i));
        double cost = (pow(temp, 2));
        outputErrors.at(i) = temp;
        Loss += cost;
    }

    Loss = Loss/target.size();
    historicalErrors.push_back(Loss);
}

void Network::BackPropagation(double LearningRate){
    //output to hidden layer
    vector<Matrix> newWeights;
    int outputLayerIndex = layers.size() - 1;
    Matrix errorMatrix(1, outputErrors.size());
    for(int i = 0; i < outputErrors.size(); i++){
        errorMatrix.SetVal(0, i, outputErrors.at(i));
    }
    Matrix prevact = layers.at(outputLayerIndex -1).toMatrixActivated().transpose();
    Matrix Gradients = prevact * errorMatrix;

    Matrix adjustedWeights = weights.at(outputLayerIndex - 1) - (Gradients * LearningRate);
    newWeights.push_back(adjustedWeights);

    ///BACKPROP
    for(int i = outputLayerIndex -2; i >= 0; i--){
        Matrix temp = (weights.at(i + 1) * errorMatrix.transpose()).transpose() * layers.at(i).toMatrixDerived();
        errorMatrix = temp;
        Gradients = layers.at(i).toMatrixActivated().transpose() * errorMatrix;
        adjustedWeights = weights.at(i) - (Gradients * LearningRate);
        newWeights.push_back(adjustedWeights);
    }

    ///SGD
    for(int i = 0; i <= outputLayerIndex - 1; i++){
        weights.at(outputLayerIndex - 1 - i) = newWeights.at(i);
    }

}
