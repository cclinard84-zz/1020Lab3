/*  File: racer.cpp
 *  Author: Matt Clinard
 *  Date: 11/19/17
 *  Description: this file is used with lab3 - Runners lab
 */
 #include "racer.h"

using std::vector;
using std::ifstream;
using std::getline;
using std::string;
using std::stringstream;

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

//Overloaded operator<< for the racer class
ostream& operator<<(ostream& outStream, const Racer& r){
    outStream << r.racerName << " " << r.racerNumber << " " << r.stringifiedRaceTime << std::endl;
    return outStream;
}

//Overloaded operator= for the racer class
void Racer::operator= ( const Racer& r ) {
    this->racerName = r.racerName;
    this->stringifiedRaceTime = r.stringifiedRaceTime;
    this->racerNumber = r.racerNumber ;
    this->totalRaceDistance = r.totalRaceDistance;
    this->totalRaceSpeed = r.totalRaceSpeed;
    this->totalRaceTime = r.totalRaceTime;
    this->sensors = r.sensors;
}

/* welcome: This function welcomes the user and gives a brief description of the program.
*  Parameters: none
*  Returns: nothing
*/
void welcome(){
    std::cout << "Welcome to Cheat Finder 9000!\n" << std::endl;
    std::cout << "Just supply the name of a text file and I will do the rest!\n" << endl;
    std::cout << "An asterisk beside the name of the racer denotes possible cheating (skipped sensors or speed > 14 mph).\n" << endl;
}

/* openFile: This function asks the user for the inputFile name and opens the ifstream
*  Parameters: input - ifstream variable name
* 			   inputFile - string that the user enters
*  Returns: nothing
*/
void openFile( ifstream &input, string &inputFile ){
	std::cout << "Please enter the file name: ";
	std::cin >> inputFile;
	input.open(inputFile.c_str( ));
    std::cout << std::endl;
}

/* checkFileFail: This function checks to make sure the file does exist and is not empty.
*  Parameters: input - ifstream variable name
* 			   inputFile - string that the user enters
*  Returns: Nothing
*/
void checkFileFail( ifstream &input, string inputFile){
	
	char c;

	if (input.fail( )){
		std::cout << "The file " << inputFile << " does not exist.\n";
		exit(1);
	}
        input.get(c);
        if (input.eof( )){
                std::cout << "The file " << inputFile << " is empty.\n";
                exit(1);
        }
       	input.putback(c);
	return;
}

/* printRacers: This function prints the racers based on the overloaded output operator.
*  Parameters: racers - a vector of Racer objects
*  Returns: Nothing
*/
void printRacers(vector<Racer>& racers){
    std::cout << "Name" << "    " << "Number" << "     " << "Time" << endl;
    std::cout << "-------------------------------" << endl;
     for(std::vector<Racer>::iterator it = racers.begin(); it != racers.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

/* getMilesPerHour: This function calculates the miles per hour of a racer.
*  Parameters: raceDistance - total distance of the race
*              racerTime - total time it took the racer to run the race
*  Returns: a double that is roughly the speed of the racer in MPH
*/
double getMilesPerHour(double raceDistance, int racerTime){
    return (double)(raceDistance /racerTime) * 1000 * 60 * 60;
}

/* findCheaters: This function determines if a racer could have possibly cheated.
*  Parameters: raceers - a vector of racer objects
*              raceDistance - total distance of the race
*  Returns: nothing
*/
void findCheaters(vector<Racer>& racers, double raceDistance){
    string tempStr = "";
    double tempMph;
    for(vector<Racer>::iterator it = racers.begin(); it != racers.end(); ++it){
        tempMph = getMilesPerHour(raceDistance, it->getTotalRaceTime());
        if(tempMph > 14 || it->possibleCheater == true){
            
            tempStr = tempStr.append("*");
            tempStr.append(it->getRacerName());
            it->setRacerName(tempStr);
            tempStr = "";
        }
        
    }
}

/* stringifyRaceTime: This function turns the time into a string.
*  Parameters: r - a racer object
*  Returns: nothing
*/
void stringifyRaceTime(Racer& r){
    //Using this for printing later.
    int seconds = (int) (r.getTotalRaceTime() / 1000) % 60 ;
    int minutes = (int) ((r.getTotalRaceTime() / (1000*60)) % 60);
    int hours   = (int) ((r.getTotalRaceTime() / (1000*60*60)) % 24);
    int milliseconds = (int) (r.getTotalRaceTime() / 1000) % 1000 ;
    r.stringifiedRaceTime = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds) + ":" + std::to_string(milliseconds);
}

/* getRaceInfo: This function takes the first read of the file as the race information.
*  Parameters: tempArray - a tempArray with all of the first read info
*              startTime - start time of the race
*              totalSensors - total number of sensors in the race
*              raceDistance - total distance of the race in miles
*  Returns: nothing
*/
void getRaceInfo(char tempArray[], int& startTime, int& totalSensors, double& raceDistance){
    char * charPtr;
    int i;
    
    //Tokenize this ishte and extract info
    charPtr = strtok(tempArray, ":");
    string hour(charPtr);
    
    charPtr = strtok(NULL, ":");
    string minutes(charPtr);
    
    charPtr = strtok(NULL, ":");
    string seconds(charPtr);
    
    charPtr = strtok(NULL, ";");
    string milliseconds(charPtr);
    
    charPtr = strtok(NULL, ";");
    string sensors(charPtr);
    
    charPtr = strtok(NULL, ";");
    string totalMiles(charPtr);
    
    //Convert hours to milliseconds
    stringstream shour(hour);
    shour >> i;
    startTime += 3600000 * i;
    
    //Parse and Convert minutes to milliseconds
    stringstream sminute(minutes);
    sminute >> i;
    startTime += 60000 * i;
    
    //Parse and Convert seconds to milliseconds
    stringstream ssecond(seconds);
    ssecond >> i;
    startTime += 1000 * i;
    
    //Parse and Really?
    stringstream smsecond(milliseconds);
    smsecond >> i;
    
    //Yep
    startTime += i;
    
    //Parse sensors 
    stringstream ssensors(sensors);
    ssensors >> totalSensors;
    
    //Parse distance
    stringstream smiles(totalMiles);
    smiles >> raceDistance;
    
}

/* convertTime: This function converts the time from hours minutes seconds and milliseconds to milliseconds.
*  Parameters: tempArray - a tempArray with all of the first read info
*              tempRacer - temporary racer object
*              time - total time in milliseconds
*  Returns: nothing
*/
void convertTime(Racer& tempRacer, char tempArray[], int& time){
    char * charPtr;
    int i;
    
    //Tokenize this ishte and extract info
    charPtr = strtok(tempArray, ":");
    if(charPtr != NULL){
        string hour(charPtr);
    
        charPtr = strtok(NULL, ":");
        string minutes(charPtr);
    
        charPtr = strtok(NULL, ":");
        string seconds(charPtr);
    
        charPtr = strtok(NULL, ";");
        string milliseconds(charPtr);

        //Convert hours to milliseconds
        stringstream shour(hour);
        shour >> i;
        time += 3600000 * i;
    
        //Parse and Convert minutes to milliseconds
        stringstream sminute(minutes);
        sminute >> i;
        time += 60000 * i;
    
        //Parse and Convert seconds to milliseconds
        stringstream ssecond(seconds);
        ssecond >> i;
        time += 1000 * i;
    
        //Parse and Really?
        stringstream smsecond(milliseconds);
        smsecond >> i;
    
        //Yep
        time += i;
        
    }
    
}

/* convertTime: This function takes information from a file read, parses it, then puts the information into a racer object
 *              which is then pushed into a vector.
*  Parameters: tempArray - a tempArray with file read information
*              data - a vector of racer objects
*              totalSensors - Number of sensors used in the race
*  Returns: nothing
*/
void getRacerData(vector<Racer>& data, char tempArray[], int totalSensors){
    Racer tempRacer;
    Sensor tempSensor[totalSensors];
    vector<Sensor> senseVector;
    string timeArray[totalSensors];
    char * charPtr;
    int tempNumber;
    
    //Racer name
    charPtr = strtok(tempArray, ";");
    tempRacer.setRacerName(charPtr);    
    //Racer number
    charPtr = strtok(NULL, ";");
    stringstream racerNum(charPtr);
    racerNum >> tempNumber;
    tempRacer.setRacerNumber(tempNumber);    
    //Sensor info
    for(int i = 0; i < totalSensors; i++){
        
        //Parse and Convert sensor number
        charPtr = strtok(NULL, ";");
        if(charPtr != NULL){
            stringstream ssensorNum(charPtr);
            ssensorNum >> tempSensor[i].number;
        
            //Parse and Convert mile marker
            charPtr = strtok(NULL, ";");
            string tempMileMarker(charPtr);
            stringstream sMileMarker(charPtr);
            sMileMarker >> tempSensor[i].mileMarker;
        
            //Grab times
            charPtr = strtok(NULL, ";");
            timeArray[i] = charPtr;        }
        else if(charPtr == NULL && i != totalSensors-1){
            tempSensor[i].number = i;
            tempSensor[i].mileMarker = 0;
            timeArray[i] = "";
            tempRacer.possibleCheater = true;
        }
    }
    
    //Add time and sensor information to racer
    for(int j = 0; j < totalSensors; j++ ){
        char tempTimeArray[256] = {0};
        strcpy(tempTimeArray,timeArray[j].c_str());
        convertTime(tempRacer, tempTimeArray, tempSensor[j].timestamp.time);
        if(j == 0){
            tempRacer.racerStartTime = tempSensor[j].timestamp.time;
        }
        else{
            if(tempSensor[j].timestamp.time == 1){
                tempRacer.racerFinishTime = tempSensor[j-1].timestamp.time;
            }
            else{
                tempRacer.racerFinishTime = tempSensor[j].timestamp.time;            
            }
        }
        senseVector.push_back(tempSensor[j]);
    }
    tempRacer.setSensors(senseVector);
    tempRacer.setTotalRaceTime(tempRacer.racerFinishTime - tempRacer.racerStartTime);
    stringifyRaceTime(tempRacer);
    data.push_back(tempRacer);
}

/* readFile: Reads the file and puts each job object into an array of structures
*  Parameters: data - an vector of Racer objects
*              startTime - time the race started
*              totalSensors - total number of sensors in the race
*              raceDistance - raceDistance in miles
*              input - ifstream variable name
*	 Precondition: File exists, is valid, and has opened successfully
*	 Postcondition: array of job structures filled to i
*	 Returns: number of job structures created
*/
void readFile(vector<Racer>& data, int& startTime, int& totalSensors, double& raceDistance, ifstream& input){
    
    //Boolean to test if race information has been retrieved
    bool firstLine = false;
    
    string line;
    getline( input, line );
    while ( true ) {
        char tempArray[256] = {0};
        strcpy(tempArray, line.c_str());
        
        //if first read go here because the first line is race information
        if(firstLine == false){
            getRaceInfo(tempArray, startTime, totalSensors, raceDistance);
            firstLine = true;
            getline( input, line );
        }
        else{
            if(input.eof()){
                getRacerData(data, tempArray, totalSensors);
                break;
            }
            else{
                getRacerData(data, tempArray, totalSensors);
                getline( input, line);
            }
        }
    }
    input.close();
}
