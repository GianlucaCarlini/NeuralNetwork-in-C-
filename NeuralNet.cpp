#include <iostream>
#include "Neuron.cpp"
#include "Matrix.cpp"
#include "Layer.cpp"
#include "Network.cpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


int main(){

    srand((unsigned) time(NULL));

    vector<vector<double>> DataSet;
    vector<vector<double>> Targets;

    for(int i = 0; i < 50; i++){
        vector<double> instance;
        for(int j = 0; j < 4; j++){
            instance.push_back((double)rand()/RAND_MAX);
        }
        DataSet.push_back(instance);
    }

    for(int i = 0; i < 50; i++){
        vector<double> instance;
        instance.push_back((DataSet.at(i).at(0) - DataSet.at(i).at(1))/(pow(DataSet.at(i).at(2),DataSet.at(i).at(3)) + 0.01));
        Targets.push_back(instance);
    }

//    for(int i = 0; i < 50; i++){
//        cout << DataSet.at(i).at(0) << "\t" << DataSet.at(i).at(1) << "\t" << DataSet.at(i).at(2) << "\t" << DataSet.at(i).at(3) << "\t";
//        cout << Targets.at(i).at(0) << endl;
//    }
//
    vector<int> structure;
    structure.push_back(4);
    structure.push_back(10);
    structure.push_back(10);
    structure.push_back(1);

    ///TRAINING

    Network n(structure);
    double error = 0;
    for(int i = 0; i < 200; i++){
        double meanError = 0;
        cout << "EPOCH," << i << "\t" ;
        for(int j = 0; j < DataSet.size(); j ++){
            n.setInputs(DataSet.at(j));
            n.setTarget(Targets.at(j));
            n.FeedForward();
            n.SetError();

            error = n.getLoss();

            meanError +=error;
            n.BackPropagation(0.1/(1 + (0.02*i)));
        }
        meanError /= DataSet.size();
        cout << "MEAN ERROR \t" << meanError << endl << "-------------" << endl;
    }

//
//    n.setInputs(input);
//
//    n.setTarget(target);
//
//
//    for(int i = 0; i < 10; i++){
//
//    n.FeedForward();
//
//    n.SetError();
//
//    m = n.GetOutput();
//
//    double error = n.getLoss();
//    cout << "OUTPUT\t";
//    m.PrintMatrix();
//    cout << endl;
//    cout << "ERROR\t" << error << endl;
//    cout << "-------------" << endl;
//
//    n.BackPropagation(0.01);
//    }

}
