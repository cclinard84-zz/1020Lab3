#ifndef TIMESTAMP_H
#define TIMESTAMP_H


class Timestamp{
public:
    Timestamp();
    Timestamp(int);
    int time; //in milliseconds
};

Timestamp::Timestamp(){
    this->time = 1;
}
Timestamp::Timestamp(int t){
    this->time = t;
}
#endif