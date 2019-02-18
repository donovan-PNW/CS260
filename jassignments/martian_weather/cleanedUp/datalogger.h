#ifndef DATALOGGER_H
#define DATALOGGER_H
#include <iostream>
#include <fstream>
#include "weatherdata.h"
#include "linkedlist.h"

class datalogger
{
public:
    datalogger();
    datalogger(int timestamp, int temperature, int windspeed);
    datalogger(const datalogger& datalogger)=delete;
    ~datalogger();
    

    void addData(int timestamp, int temperature, int windspeed);
    void addToList();
    void printReport(const char* label);
    //void doTheThing(linkedList workingList);
    void runTheNumbers();
    bool containsTimestamp(int timestamp) const;
    void removeData(int timestamp);

private:
    weatherdata currentEntry;
    linkedList workingList;
    int timestamp;
    int temperature;
    int windspeed;

    int totalEntries;
    int lowTime;
    int highTime;
    int belowneg50;
    int above0;
    double mostCommonTemperature;
    int zeroWind;
    int fastWind;
    int mostCommonWind;

    int avgT0;
    int avgT1;
    int avgT2;
    int avgT3;
    int avgT4;
    int avgT5;
    int avgT6;
    int avgT7;
    int avgT8;
    int avgT9;

    int avgW0;
    int avgW1;
    int avgW2;
    int avgW3;
    int avgW4;
    int avgW5;
    int avgW6;
    int avgW7;
    int avgW8;
    int avgW9;


//TODO ADD LATER
//    void removeData();

};

#endif
