#ifndef SENSOR_H
#define SENSOR_H

#include "timestamp.h"

class Sensor{
public:
    int number;
    Timestamp timestamp;
    double mileMarker;
};
#endif