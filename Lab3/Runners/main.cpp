#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "racer.h"

using std::vector;

int main(int argc, char **argv)
{
    vector<Racer> racers;
    int startTime = 0;
    int totalSensors;
    double raceDistance; 
    std::ifstream input;
    string inputFile;
    
    welcome();
    openFile(input, inputFile);
    checkFileFail(input, inputFile);
    readFile(racers, startTime, totalSensors, raceDistance, input);
    std::sort(racers.begin(), racers.end());
    findCheaters(racers, raceDistance);
    printRacers(racers);
    //std::cout << startTime << std::endl;
    //std::cout << totalSensors << std::endl;
    //std::cout << raceDistance << std::endl;
}
