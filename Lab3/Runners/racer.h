#ifndef racer_h
#define racer_h
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "sensor.h"

using std::string;
using std::vector;
using std::ostream;
using std::endl;

class Racer{
public:
    Racer();
    Racer(vector<Sensor>, string, int, double, double);
    
    string stringifiedRaceTime;
    int racerStartTime;
    int racerFinishTime;
    bool possibleCheater = false;
    
    //Overloaded operator declarations
    friend std::ostream& operator<<( ostream&, const Racer&);
    void operator=( const Racer& );
    
    //Comparator
    bool operator<( Racer& r ) { return this->totalRaceTime < r.totalRaceTime; }
    
    //Setters for private data fields
    void setRacerName(string racerName){ this->racerName = racerName; }
    void setRacerNumber(int racerNumber){ this->racerNumber = racerNumber; }
    void setTotalRaceTime(int totalRaceTime){ this->totalRaceTime = totalRaceTime; }
    void setTotalDistance(double totalRaceDistance){ this->totalRaceDistance = totalRaceDistance; }
    void setTotalRaceSpeed(double totalRaceSpeed){ this->totalRaceSpeed = totalRaceSpeed; }
    void setSensors(vector<Sensor> sensors){ this->sensors = sensors; }
    
    //Getters for private data fields
    string getRacerName() const { return this->racerName; }
    int getRacerNumber() const { return this->racerNumber; }
    int getTotalRaceTime() const { return this->totalRaceTime; }
    double getTotalRaceDistance() const { return this->totalRaceDistance; }
    double getTotalRaceSpeed() const { return this->totalRaceSpeed; }
    vector<Sensor> getSensors() { return this->sensors; }
private:
    vector<Sensor> sensors;
    string racerName;
    int racerNumber;
    int totalRaceTime; //milliseconds
    double totalRaceDistance;
    double totalRaceSpeed;
    
};

//Default constructor
Racer::Racer(){
    this->racerName = "default";
    this->totalRaceDistance = 1.0;
    this->totalRaceSpeed = 1.0;
    this->racerNumber = -1;
}

//Overloaded constructor
Racer::Racer(vector<Sensor> sensors, string racerName, int racerNumber, double totalDistance, double totalSpeed){
    this->sensors = sensors;
    this->racerNumber = racerNumber;
    this->totalRaceDistance = totalDistance;
    this->totalRaceSpeed = totalSpeed;
}

ostream& operator<<(ostream& outStream, const Racer& r){
    outStream << r.racerName << " " << r.racerNumber << " " << r.stringifiedRaceTime << std::endl;
    return outStream;
}

void Racer::operator= ( const Racer& r ) {
    this->racerName = r.racerName;
    this->stringifiedRaceTime = r.stringifiedRaceTime;
    this->racerNumber = r.racerNumber ;
    this->totalRaceDistance = r.totalRaceDistance;
    this->totalRaceSpeed = r.totalRaceSpeed;
    this->totalRaceTime = r.totalRaceTime;
    this->sensors = r.sensors;
}
#endif