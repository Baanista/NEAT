
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

// float randomWeight()
// {
//     return((float(rand())/float((RAND_MAX)) * 2) - 1);
// }

class RNetworker
{
    public:
        vector<vector<vector<vector<double> > > > Brain;


        

vector<double> plugin_info(const vector<double>& data)
{
    
    vector<double> layer = data;
    vector<double> node;
    double w1;
    double w2;
    double num;
    double sum;
    //cout << "test" << randomWeight() << endl;

    for (int i = 0; i < Brain.size(); i++)
    {
        
        vector<double> templayer;
        for (int f = 0; f < Brain[i].size(); f++)
        {
            
            for (int j = 0; j < Brain[i][f].size() - 1; j++)
            {
                //cout << "error" << endl;
                w1 = Brain[i][f][j][0];
                w2 = Brain[i][f][j][1];

                num = (w1 * layer[j]) + w2;
                node.push_back(num);
                
            }
            
            sum = 0;
            
            for (int k = 0; k < node.size(); k++)
            {
                sum += node[k];
            }
            if (sum >= 0)
            {
                templayer.push_back(sum);
            }
            else
            {
                templayer.push_back(0);
            }
            
            node.clear();
            
        }
        layer = templayer;
    }

    return layer;
}
    double scorer(vector<double> input, vector<double> poutput)
    {
        double score = 0;

        vector<double> output = plugin_info(input);

        for (int i = 0; i < output.size(); i++)
        {

            score += abs(output[i] - poutput[i]);
        }

        return(score);
    }

};

#endif