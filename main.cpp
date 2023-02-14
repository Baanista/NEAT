//
//  main.cpp
//  NEAT
//
//  Created by Nicholas Maloney on 9/13/22.
//

#include <iostream>
using namespace std;
#include<cstdlib>
#include<random>
//#include "NNetwork.hpp"
#include "RNetwork.hpp"
#include <time.h>
#include <stdio.h>      
#include <vector>
#include <iomanip>
vector<vector<vector<vector<double> > > > zerostart(vector<int> structure)
{
    int layers = structure.size();
    vector<vector<vector<vector<double> > > > output;
    output.resize(layers - 1);
    for (int i = 0; i < layers -1; i++)
    {
        
        int nodes = structure[i];
        output[i].resize(structure[i + 1]);
        for (int a = 0; a < structure[i+1]; a++)
        {
            output[i][a].resize(nodes + 1);
            for (int j = 0; j < structure[i]; j++)
            {
                
                output[i][a][j].resize(2);
                output[i][a][j][0] = i + a * j;
                output[i][a][j][1] = i + a * j +1;
            }
    }
    }

    return output;
}

void printneuralnetwork(const vector<vector<vector<vector<double>  > > >& net) {
    for (const auto& a : net) {
        for (const auto& b : a) {
            cout << ' ';
            for (const auto& c : b) {
                cout << ' ';
                for (const auto& d : c) {
                    cout << d << " ";
                }
                cout << ' ';
            }
            cout << ' ';
        }
        cout << endl;
    }
}

void print_vector(const vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    RNetworker RNet;

    vector<int> bstruct;
    bstruct.push_back(3);
    bstruct.push_back(3);
    bstruct.push_back(3);
    


    
    
    vector<vector<vector<vector<double> > > > temp = zerostart(bstruct);
    RNet.Brain = temp;
    



    vector<double> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    
    printneuralnetwork(RNet.Brain);
    
    //vector<double> output = RNet.plugin_info(input);
    //print_vector(input);
    //print_vector(output);
}