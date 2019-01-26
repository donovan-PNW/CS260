#include "datalogger.h"
#include <iostream>

using namespace std;

datalogger::datalogger()
{
    timestamp = -1;
    temperature = -1;
    windspeed = -1;
}

datalogger::datalogger(int tempTimestamp, int tempTemperature, int tempWindspeed)
{
    timestamp = tempTimestamp;
    temperature = tempTemperature;
    windspeed = tempWindspeed;
}

datalogger::~datalogger()
{
}

void datalogger::addData(const int tempTimestamp, const int tempTemperature, const int tempWindspeed)
{
    currentEntry.setTimestamp(tempTimestamp);
    currentEntry.setTemperature(tempTemperature);
    currentEntry.setWindspeed(tempWindspeed);
    workingList.insert(currentEntry);
}

void datalogger::runTheNumbers()
{
    int lowTime;
    int highTime;
    int totalEntries;
    int belowneg50;
    int above0;
    int mostCommonTemperature;
    int mostCommonWindspeed;

    int currentTime;
    int currentTemperature;
    int currentWindspeed;
 
    currentTime = workingList.pullTime();
    //**********************************************//
    //you need to do a while loop with an incrementer
    //    int listSize
    //    int index
    //    for(index=0; index <= listSize, listSize++)
    //    {
    //        currentTime = workingList.pullTime(index);
    //        if(currentTime < lowTime)
    //        {}
    //        if(currentTime > highTime)
    //        {}
    //    }
    //currentTemperature = workingList.pullTemperature();
    //currentWindspeed = workingList.pullWindspeed();
    //**********************************************//




}

void datalogger::printReport(const char* label)
{
    //be sure to COUT label!!
    workingList.printMe();

    return;
}







//containsTimestamp(timestamp)
























