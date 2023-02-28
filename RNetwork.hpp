
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
#include <iomanip>



float randomWeight()
{
    return((float(rand())/float((RAND_MAX))));
}



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
    // cbrain is the changed brain
    void changer(double changing_value)
    {
        double add = changing_value * .5;
        double multiply = changing_value;

        for (int l = 0; l < Brain.size(); l++) {

            for (int a = 0; a < Brain[l].size(); a++) {
                
                for (int f = 0; f < Brain[l][a].size() - 1; f++) {
                    //cout << Brain[l][a][f][0] << endl;
                    //cout << Brain[l][a][f][1] << endl;
                    Brain[l][a][f][0] += randomWeight() * multiply - add;
                    Brain[l][a][f][1] += randomWeight() * multiply - add;

                    }

            }
        }


    }

    void adaptor(vector<vector<double> > input, vector<vector<double> > output, int batch)
    {
        cout << "debug" << endl;
        vector<vector<vector<vector<double> > > > edited_brain = Brain;

        double highest_score = 0;

        for (int i = 0; i < input.size(); i++)
        {
            highest_score += scorer(input[i],output[i]);
        }
        vector<vector<vector<vector<double> > > > best_brain = Brain;
        RNetworker temp_brain;
        cout << "size" << input.size() << endl;
        double temp_score = 0;
        
        for (int i = 0; i < batch; i++)
        {
            //cout << "debug" << endl;
            
            temp_score = 0;
            
            temp_brain.Brain = edited_brain;

            temp_brain.changer(2);

            for (int i = 0; i < input.size(); i++)
            {
                temp_score += temp_brain.scorer(input[i], output[i]);
                //cout << "debug" << endl;
            }
            if (temp_score > highest_score)
            {
                highest_score = temp_score;

                Brain = temp_brain.Brain;
            }

        }



    }

    double scorer(vector<double> input, vector<double> poutput)
    {
        double score = 0;

        vector<double> output = plugin_info(input);

        for (int i = 0; i < output.size(); i++)
        {
            cout << "thing" << abs(output[i] - poutput[i]) << endl;
            score += abs(output[i] - poutput[i]);
        }

        return(score);
    }

};

#endif