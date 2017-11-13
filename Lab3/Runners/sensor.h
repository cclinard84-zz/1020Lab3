#ifndef SENSOR_H
#define SENSOR_H

#include "timestamp.h"

class Sensor{
public:
    Sensor();
    Sensor(int, Timestamp&, double);
    int number;
    Timestamp timestamp;
    double mileMarker;
};

Sensor::Sensor(){
    number = 1;
    timestamp = Timestamp(1);
    mileMarker = 1.0;
}

Sensor::Sensor(int num, Timestamp& t, double marker){
    this->number = num;
    this->timestamp = t;
    this->mileMarker = marker;
}
#endif