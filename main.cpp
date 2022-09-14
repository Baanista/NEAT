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
#include "NNetwork.hpp"
#include <time.h>
#include <stdio.h>      


int main() {
    Network Brain(10, 10);
    int v2;
    int v1;
    while (true) {
        srand (time(NULL));

            // Get a random number
        v1 = rand() % 12000000;
        v2 = rand(v1) % 100 + 1;
        cout << v2 << endl;
    }
    

        // Print the random number
    //cout<<v2<<endl;
    
    //cout << Brain.;
    
    
}
