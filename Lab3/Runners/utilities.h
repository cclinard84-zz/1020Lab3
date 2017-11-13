#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <iostream>
#include <cstring>

#include "racer.h"
#include "sensor.h"
#include "timestamp.h"

using std::vector;
using std::ifstream;
using std::getline;
using std::string;

vector<Racer> readFile(vector<Racer>& data){
    Racer tempRacer;
    bool firstLine = false;
    const char delim[2] = ";";
    
    ifstream input("input.txt");
    string line;
    getline( input, line );
    while ( !input.eof() ) {
        char tempArray[256];
        strcpy(tempArray, line.c_str());
        if(firstLine == false){
            
        }
       
        
        
        getline( input, line );
    }
    
    return data;
}

#endif