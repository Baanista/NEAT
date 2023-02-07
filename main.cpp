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

vector<vector<vector<double> > > zerostart(vector<int> structure)
{
    int layers = structure.size();
    vector<vector<vector<double> > > output(layers);

    for (int i = 0; i < layers; i++)
    {
        int nodes = structure[i];
        output[i].resize(nodes);

        for (int j = 0; j < nodes; j++)
        {
            output[i][j].resize(2);
            output[i][j][0] = 0.0;
            output[i][j][1] = 0.0;
        }
    }

    return output;
}



int main()
{
    RNetworker RNet;

    vector<int> bstruct = {1, 2, 1};
    vector<vector<vector<double> > > temp = zerostart(bstruct);
    RNet.Brain = temp;

    cout << RNet.Brain[0][0][0] << endl;
//
    return 0;
}