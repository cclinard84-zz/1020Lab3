#include <stdio.h>
#include <vector>
#include <algorithm>
#include "racer.h"
#include "utilities.h"

using std::vector;

int main(int argc, char **argv)
{
    vector<Racer> racers;
    int startTime = 0;
    int totalSensors;
    double raceDistance;
    
	printf("hello world\n");
    
    
    readFile(racers, startTime, totalSensors, raceDistance);
    for(std::vector<Racer>::iterator it = racers.begin(); it != racers.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::sort(racers.begin(), racers.end());
    for(std::vector<Racer>::iterator it = racers.begin(); it != racers.end(); ++it) {
        std::cout << *it << std::endl;
    }
    //std::cout << startTime << std::endl;
    //std::cout << totalSensors << std::endl;
    //std::cout << raceDistance << std::endl;
}
