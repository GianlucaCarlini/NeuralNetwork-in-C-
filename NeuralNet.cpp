#include <iostream>
#include "Neuron.cpp"
#include "Matrix.cpp"
#include "Layer.cpp"
#include "Network.cpp"
#include <vector>
#include "MatMul.cpp"
using namespace std;


int main(){
    vector<int> structure;
    structure.push_back(3);
    structure.push_back(2);
    structure.push_back(3);

    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    Network n(structure);

    n.setInputs(input);

    n.Summary();
//
//    Matrix a(2, 3);
//    Matrix b(3, 3);
//    Matrix c = a * b;
//
//    a.PrintMatrix();
//    cout << endl;
//    b.PrintMatrix();
//    cout << endl;
//    c.PrintMatrix();
//

}

