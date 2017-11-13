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
    Racer(vector<Sensor>, string, int, double, double);
    
    //Overloaded operator declarations
    friend bool operator<( const Racer&, const Racer& );
    void operator=( Racer& );
    
    //Setters for private data fields
    void setRacerName(string racerName){ this->racerName = racerName; }
    void setRacerNumber(int racerNumber){ this->racerNumber = racerNumber; }
    void setTotalRaceTime(int totalRaceTime){ this->totalRaceTime = totalRaceTime; }
    void setTotalDistance(double totalRaceDistance){ this->totalRaceDistance = totalRaceDistance; }
    void setTotalRaceSpeed(double totalRaceSpeed){ this->totalRaceSpeed = totalRaceSpeed; }
    void setSensors(vector<Sensor> sensors){ this->sensors = sensors; }
    
    //Getters for private data fields
    string getRacerName(){ return this->racerName; }
    int getRacerNumber(){ return this->racerNumber; }
    int getTotalRaceTime(){ return this->totalRaceTime; }
    double getTotalRaceDistance(){ return this->totalRaceDistance; }
    double getTotalRaceSpeed(){ return this->totalRaceSpeed; }
    vector<Sensor> getSensors(){ return this->sensors; }
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

bool operator<( const Racer& racer1, const Racer& racer2 ) {
    return racer1.totalRaceTime < racer2.totalRaceTime;
}

void Racer::operator=(Racer& r){
   r.setRacerNumber(this->getRacerNumber());
   r.setTotalDistance(this->getTotalRaceDistance());
   r.setTotalRaceSpeed(this->getTotalRaceSpeed());
   r.setTotalRaceTime(this->getTotalRaceTime());
   r.setSensors(this->getSensors());
}
#endif