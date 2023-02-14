
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
        vector<vector<vector<vector<double> > > > Brain;

    vector<double> plugin(vector<double> input)
    {
        vector<double> output;
        vector<double> templayer = input;
        
        for (int l = 0; l < Brain.size(); l++)
        {

            

            for (int a = 0; a < Brain[l].size(); a++)
            {
                for (int p = 0; p < Brain[l][a].size(); p++)
                {
                    double w1 = Brain[l][a][p][0];
                    double w2 = Brain[l][a][p][1];

                    double num = (w1 * templayer[p]) + w2;



                }
            }
        }

        return(output);
    }

};

#endif