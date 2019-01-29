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
    //do I need this? Like, as in if I have addData(int int int) do I
    //still need a parameter constructor?
    datalogger(int timestamp, int temperature, int windspeed);
    datalogger(const datalogger& datalogger)=delete;
    ~datalogger();
    

    void addData(int timestamp, int temperature, int windspeed);
    void addToList();
    void printReport(const char* label);
    //void doTheThing(linkedList workingList);
    void runTheNumbers();

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
    int mostCommonTemperature;
    int zeroWind;
    int fastWind;
    int mostCommonWind;

    double avgT0;
    double avgT1;
    double avgT2;
    double avgT3;
    double avgT4;
    double avgT5;
    double avgT6;
    double avgT7;
    double avgT8;
    double avgT9;

    double avgW0;
    double avgW1;
    double avgW2;
    double avgW3;
    double avgW4;
    double avgW5;
    double avgW6;
    double avgW7;
    double avgW8;
    double avgW9;


//TODO ADD LATER
//    void removeData();
//    void printReport();

};

#endif
