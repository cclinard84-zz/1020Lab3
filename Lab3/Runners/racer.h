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
    Racer();
    Racer(vector<Sensor>, string, double, double);
    vector<Sensor> sensors;
    string name;
    double totalRaceDistance;
    double totalRaceSpeed;
private:
    int racerNumber;
};

Racer::Racer(){
    this->name = "default";
    this->totalRaceDistance = 1.0;
    this->totalRaceSpeed = 1.0;
    this->racerNumber = -1;
}
Racer::Racer(vector<Sensor> sensors, string name, double totalDistance, double totalSpeed){
    this->sensors = sensors;
    this->name = name;
    this->totalRaceDistance = totalDistance;
    this->totalRaceSpeed = totalSpeed;
}
#endif