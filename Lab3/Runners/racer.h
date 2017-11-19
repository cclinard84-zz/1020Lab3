#ifndef RACER_H
#define RACER_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cstdio>
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
void welcome();
void openFile(std::ifstream&, string&);
void checkFileFail(std::ifstream&, string);
void printRacers(vector<Racer>& );
double getMilesPerHour(double , int );
void findCheaters(vector<Racer>& , double );
void stringifyRaceTime(Racer& );
void getRaceInfo(char[] , int& , int& , double& );
void convertTime(Racer& , char[], int& );
void getRacerData(vector<Racer>& , char[], int );
void readFile(vector<Racer>& , int& , int& , double&, std::ifstream&);


#endif