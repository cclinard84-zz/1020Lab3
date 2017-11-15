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

void convertTime(char tempArray[], int& time){
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

    //Convert hours to milliseconds
    stringstream shour(hour);
    shour >> i;
    time += 3600000 * i;
    
    //Parse and Convert minutes to milliseconds
    stringstream sminute(minutes);
    sminute >> i;
    time += 60000 * i;
    
    //Parse and Convert seconds to milliseconds
    stringstream ssecond(seconds);
    ssecond >> i;
    time += 1000 * i;
    
    //Parse and Really?
    stringstream smsecond(milliseconds);
    smsecond >> i;
    
    //Yep
    time += i;
}

void getRacerData(vector<Racer>& data, char tempArray[], int totalSensors){
    Racer tempRacer;
    Sensor tempSensor[totalSensors];
    vector<Sensor> senseVector;
    string timeArray[totalSensors];
    char * charPtr;
    int tempNumber;
    
    //Racer name
    charPtr = strtok(tempArray, ";");
    tempRacer.setRacerName(charPtr);
    std::cout << tempRacer.getRacerName() << std::endl;
    
    //Racer number
    charPtr = strtok(NULL, ";");
    stringstream racerNum(charPtr);
    racerNum >> tempNumber;
    tempRacer.setRacerNumber(tempNumber);
    std::cout << tempRacer.getRacerNumber() << std::endl;
    
    //Sensor info
    for(int i = 0; i < totalSensors; i++){
        
        //Parse and Convert sensor number
        charPtr = strtok(NULL, ";");
        stringstream ssensorNum(charPtr);
        ssensorNum >> tempSensor[i].number;
        
        //Parse and Convert mile marker
        charPtr = strtok(NULL, ";");
        string tempMileMarker(charPtr);
        stringstream sMileMarker(charPtr);
        sMileMarker >> tempSensor[i].mileMarker;
        
        //Grab times
        charPtr = strtok(NULL, ";");
        timeArray[i] = charPtr;
        std::cout << charPtr << std::endl;
    }
    for(int j = 0; j < totalSensors; j++ ){
        char tempTimeArray[256] = {0};
        strcpy(tempTimeArray,timeArray[j].c_str());
        convertTime(tempTimeArray, tempSensor[j].timestamp.time);
        senseVector.push_back(tempSensor[j]);
    }
    tempRacer.setSensors(senseVector);
    data.push_back(tempRacer);
}

void readFile(vector<Racer>& data, int& startTime, int& totalSensors, double& raceDistance){
    
    //Boolean to test if race information has been gotten
    bool firstLine = false;
    
    ifstream input("input.txt");
    string line;
    getline( input, line );
    while ( true ) {
        char tempArray[256] = {0};
        strcpy(tempArray, line.c_str());
        if(firstLine == false){
            getRaceInfo(tempArray, startTime, totalSensors, raceDistance);
            firstLine = true;
            getline( input, line );
        }
        else{
            if(input.eof()){
                getRacerData(data, tempArray, totalSensors);
                break;
            }
            else{
                getRacerData(data, tempArray, totalSensors);
                getline( input, line);
            }
        }
    }
    input.close();
}





#endif