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

vector<vector<vector<vector<double> > > > zerostart(vector<int> structure)
{
    int layers = structure.size();
    vector<vector<vector<vector<double> > > > output;
    output.resize(structure.size() - 1);
    for (int i = 0; i < layers -1; i++)
    {
        
        int nodes = structure[i];
        output[i].resize(structure[i + 1]);
        for (int a = 0; a < structure[i + 1]; a++)
        {
            output[a].resize(nodes + 1);
            for (int j = 0; j < structure[i]; j++)
            {
                
                output[i][j][a].resize(2);
                output[i][j][a][0] = 0.0;
                output[i][j][a][1] = 0.0;
            }
    }
    }

    return output;
}



int main()
{
    RNetworker RNet;

    vector<int> bstruct;
    bstruct.push_back(1);
    bstruct.push_back(2);
    bstruct.push_back(1);


    printf("hello");
    
    vector<vector<vector<vector<double> > > > temp = zerostart(bstruct);
    // RNet.Brain = temp;
    

    // cout << RNet.Brain[0][0][0][0] << endl;

}