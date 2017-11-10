#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>

class Timestamp{
public:
    Timestamp(Timestamp&);
    int time; //in milliseconds
};

Timestamp::Timestamp(Timestamp& t){
    this->time = t.time;
}
#endif