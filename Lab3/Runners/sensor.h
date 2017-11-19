/*  File: sensors.h
 *  Author: Matt Clinard
 *  Date: 11/19/17
 *  Description: this file is used with lab3 - Runners lab
 */
#ifndef SENSOR_H
#define SENSOR_H

#include "timestamp.h"

class Sensor{
public:
    //Default constructor
    Sensor(){
        number = 1;
        timestamp = Timestamp(1);
        mileMarker = 1.0;
    }
    //Overloaded Constructor
    Sensor(int marker, Timestamp& t, double num){
        this->number = num;
        this->timestamp = t;
        this->mileMarker = marker;
    }
    //Class variables
    int number;
    Timestamp timestamp;
    double mileMarker;
    void setTimestamp(int time){ this->timestamp.time = time;    }
};

#endif