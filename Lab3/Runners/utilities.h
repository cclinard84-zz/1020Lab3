#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>

#include "racer.h"
#include "sensor.h"
#include "timestamp.h"

using std::vector;
using std::ifstream;
using std::getline;
using std::string;
using std::stringstream;

void getStartTime(char tempArray[], int& startTime){
    char * charPtr;
    char delim[2] = ":";
    int i;
    
    charPtr = strtok(tempArray, delim);
    string hour(charPtr);
    charPtr = strtok(tempArray, delim);
    string minutes(charPtr);
    charPtr = strtok(tempArray, delim);
    string seconds(charPtr);
    charPtr = strtok(tempArray, delim);
    string milliseconds(charPtr);
    
    stringstream shour(hour);
    shour >> i;
    startTime += 3600000 * i;
    stringstream sminute(minutes);
    sminute >> i;
    std::cout << i << std::endl;
    startTime += 3600000 ;
}

void readFile(vector<Racer>& data, int& startTime){
    Racer tempRacer;
    bool firstLine = false;
    
    ifstream input("input.txt");
    string line;
    getline( input, line );
    while ( !input.eof() ) {
        char tempArray[256];
        strcpy(tempArray, line.c_str());
        if(firstLine == false){
            
            getStartTime(tempArray, startTime);
            firstLine = true;
            getline( input, line );
        }
        else{
            
            getline( input, line );
        }
    }
}



#endif