
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

    vector<double> plugin_info(const vector<double>& data)
{
    
    vector<double> layer = data;
    vector<double> node;

    for (int i = 0; i < Brain.size(); i++)
    {
        
        vector<double> templayer;
        for (int f = 0; f < Brain[i].size(); f++)
        {
            
            for (int j = 0; j < Brain[i][f].size(); j++)
            {
                //cout << "error" << endl;
                double w1 = Brain[i][f][j][0];
                double w2 = Brain[i][f][j][1];

                double num = (w1 * layer[j]) + w2;
                node.push_back(num);
                cout << "error" << j << endl;
            }
            
            double sum = 0;
            
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

};

#endif