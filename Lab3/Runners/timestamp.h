/*  File: timestamp.h
 *  Author: Matt Clinard
 *  Date: 11/19/17
 *  Description: this file is used with lab3 - Runners lab
 */
 #ifndef TIMESTAMP_H
#define TIMESTAMP_H

class Timestamp{
public:
    //Constructors and class variables
    Timestamp(){ this->time = 1; }
    Timestamp(int t){ this->time = t; }
    int time; //in milliseconds
};

#endif