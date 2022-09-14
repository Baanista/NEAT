
//
//  NueralNetwork.cpp
//  NEAT
//
//  Created by Nicholas Maloney on 9/13/22.
//

#ifndef NNetwork_HPP // include guard
#define NNetwork_HPP
#include <stdio.h>
#include <stdlib.h>
#include "NNetwork.hpp"
#include<cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

class Network
{
    public:
        int nodes;
        int connections;
        //cout << time << enl;
        //srand (time(NULL));

        // Get a random number
        //int v2 = rand() % 100 + 1;
        

        Network(int p1, int p2){
            nodes = p1;
            connections =  p2;
        }
};

#endif /* MY_CLASS_H */
