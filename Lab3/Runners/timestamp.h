#ifndef TIMESTAMP_H
#define TIMESTAMP_H

class Timestamp{
public:
    Timestamp(){ this->time = 1; }
    Timestamp(int t){ this->time = t; }
    int time; //in milliseconds
};

#endif