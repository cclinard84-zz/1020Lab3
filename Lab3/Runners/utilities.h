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

void getRaceInfo(char tempArray[], int& startTime, int& totalSensors, double& raceDistance){
    char * charPtr;
    int i;
    
    //Tokenize this ishte and extract info
    charPtr = strtok(tempArray, ":");
    string hour(charPtr);
    
    charPtr = strtok(NULL, ":");
    string minutes(charPtr);
    
    charPtr = strtok(NULL, ":");
    string seconds(charPtr);
    
    charPtr = strtok(NULL, ";");
    string milliseconds(charPtr);
    
    charPtr = strtok(NULL, ";");
    string sensors(charPtr);
    
    charPtr = strtok(NULL, ";");
    string totalMiles(charPtr);
   
    
    //Convert hours to milliseconds
    stringstream shour(hour);
    shour >> i;
    startTime += 3600000 * i;
    
    //Parse and Convert minutes to milliseconds
    stringstream sminute(minutes);
    sminute >> i;
    startTime += 60000 * i;
    
    //Parse and Convert seconds to milliseconds
    stringstream ssecond(seconds);
    ssecond >> i;
    startTime += 1000 * i;
    
    //Parse and Really?
    stringstream smsecond(milliseconds);
    smsecond >> i;
    
    //Yep
    startTime += i;
    
    //Parse sensors 
    stringstream ssensors(sensors);
    ssensors >> totalSensors;
    
    //Parse distance
    stringstream smiles(totalMiles);
    smiles >> raceDistance;
    
}

void readFile(vector<Racer>& data, int& startTime, int& totalSensors, double& raceDistance){
    Racer tempRacer;
    bool firstLine = false;
    
    ifstream input("input.txt");
    string line;
    getline( input, line );
    while ( !input.eof() ) {
        char tempArray[256];
        strcpy(tempArray, line.c_str());
        if(firstLine == false){
            getRaceInfo(tempArray, startTime, totalSensors, raceDistance);
            firstLine = true;
            getline( input, line );
        }
        else{
            
            getline( input, line );
        }
    }
    input.close();
}





#endif