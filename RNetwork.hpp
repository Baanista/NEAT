
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


class RNetworker
{
    public:
        vector< vector<vector<double> > > Brain;

    vector<double> plugin(vector<double> input)
    {
        vector<double> output;
        
        for (int l = 0; l < Brain.size(); l++)
        {
            for (int p = 0; p < Brain.size(); p++)
            {
                
            }
        }

        return(output);
    }

};

#endif