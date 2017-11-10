#ifndef racer_h
#define racer_h
#include <cstdlib>
#include <vector>
#include <string>
#include "sensor.h"

using std::string;

using std::vector;

class Racer{
public:
    vector<Sensor> sensors;
    string name;
    int racerNumber;
    double totalRaceDistance;
    double totalRaceSpeed;
};

#endif