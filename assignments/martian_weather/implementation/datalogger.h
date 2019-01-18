#ifndef DATALOGGER_H
#define DATALOGGER_H
#include <iostream>
#include <fstream>
#include"weatherdata.h"

class datalogger
{
public:
    datalogger();
    //do I need this? Like, as in if I have addData(int int int) do I
    //still need a parameter constructor?
    datalogger(int timestamp, int temperature, int windspeed);
    datalogger(const datalogger& datalogger)=delete;
    ~datalogger();
    

    void addData(int timestamp, int temperature, int windspeed);

private:
    //MAKE IT A NODE????
    weatherdata currentEntry;
    int timestamp;
    int temperature;
    int windspeed;


//TODO ADD LATER
//    void removeData();
//    void printReport();

};

#endif
