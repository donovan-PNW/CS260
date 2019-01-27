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
    int listSize = 0;
    //int mostCommon = 0;
    //int highScore = 0;
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
    //must be more graceful than this?
    int lowTime = 150000000;
    int highTime = 0;
    int totalEntries = 0;
    int belowneg50 = 0;
    int above0 = 0;
    int mostCommonTemperature;
    int mostCommonWindspeed;

    int currentTime = 0;
    int currentTemperature;
    int currentWindspeed;
 
    totalEntries = workingList.totalizer() - 1;
    std::cout << "Totals: " << totalEntries << endl;


    //currentTime = workingList.pullTime(0);
    //std::cout << "currentTime: " << currentTime << endl;
    //currentTime = workingList.pullTime(5);
    //std::cout << "currentTime: " << currentTime << endl;
    for(int index = 0; index < totalEntries; index++)
    {
        currentTime = workingList.pullTime(index);
        std::cout << "current time: " << currentTime << '\n';
        //if(currentTime > highTime)
        //    highTime = currentTime;
        //else if(currentTime < lowTime)
        //    lowTime = currentTime;

    }
    
    //std::cout << "high time: " << highTime
    //<< "low time: " << lowTime;

    //ok here's what I'm thinking now: just call a function workingList.listSize();
    //which will return listSize (implemented inside linkedlist)
    //this will just do a for loop
    //**********************************************//
    //you need to do a while loop with an incrementer
    //    int listSize
    //    int index
    //    //if this gives a seg fault try index < listSize
    //    //also if you need to get the last one off, you can
    //    //just use listSize-1.
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
    //workingList.printMe();
    runTheNumbers();
    return;
}







//containsTimestamp(timestamp)
























