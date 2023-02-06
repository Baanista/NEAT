
//
//  NueralNetwork.cpp
//  NEAT
//
//  Created by Nicholas Maloney on 9/13/22.
//



#ifndef RNetwork_HPP // include guard
#define RNetwork_HPP
#include <stdio.h>
#include <stdlib.h>
#include "NNetwork.hpp"
#include<cstdlib>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

vector< vector<vector<double> > > zerostart(vector<int> structure)
{
    vector<vector<vector<double[2]> >> output;

    for (int i = 0; i < structure.size(); i++)
    {
        for (int i1 = 0; i1 < structure[i]; i1++)
        {
            output[i][i1][0] = 0;
            output[i][i1][1] = 0;
        }
    }
    return(output);
};

class RNetwork
{
    public:
        vector< vector<vector<double> > > Brain;

};

#endif