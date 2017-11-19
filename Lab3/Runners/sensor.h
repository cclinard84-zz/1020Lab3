#ifndef SENSOR_H
#define SENSOR_H

#include "timestamp.h"

class Sensor{
public:
    Sensor(){
        number = 1;
        timestamp = Timestamp(1);
        mileMarker = 1.0;
    }
    Sensor(int marker, Timestamp& t, double num){
        this->number = num;
        this->timestamp = t;
        this->mileMarker = marker;
    }
    int number;
    Timestamp timestamp;
    double mileMarker;
    void setTimestamp(int time){ this->timestamp.time = time;    }
};

#endif