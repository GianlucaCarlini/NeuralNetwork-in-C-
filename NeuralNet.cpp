#include <iostream>
#include "Neuron.cpp"
#include "Matrix.cpp"
#include "Layer.cpp"
#include "Network.cpp"
#include <vector>
using namespace std;

double function(vector<double>input){
    double x = 0;
    x += input.at(0);
    x *= input.at(1);
    x /= input.at(2);
    return x;
}

int main(){
    vector<int> structure;
    structure.push_back(3);
    structure.push_back(3);
    structure.push_back(1);

    vector<double> input;
    input.push_back(2.0);
    input.push_back(4.0);
    input.push_back(3.0);


    vector<double> target;
    target.push_back(function(input));

    Network n(structure);

    n.setInputs(input);

    n.setTarget(target);

    n.Summary();

    Matrix m = n.GetOutput();


    for(int i = 0; i < 20; i++){

    n.FeedForward();

    n.SetError();

    m = n.GetOutput();

    double error = n.getLoss();
    cout << "OUTPUT\t";
    m.PrintMatrix();
    cout << endl;
    cout << "ERROR\t" << error << endl;
    cout << "-------------" << endl;

    n.BackPropagation(0.01);
    }

}
