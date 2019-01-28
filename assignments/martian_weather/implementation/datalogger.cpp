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
    int lowTime = 1500000000;
    int highTime = 0;
    int totalEntries = 0;
    int belowneg50 = 0;
    int above0 = 0;
    int mostCommonTemperature = 0;
    int mostCommonWindspeed = 0;

 
    totalEntries = workingList.totalizer() - 1;
    //WHY DO I NEED TO SHIFT THIS TO GET IT TO WORK?
    std::cout << "Totals: " << totalEntries << endl;

//**TIME*******************************************************//
    
    int currentTime = 0;
    for(int index = 0; index < totalEntries; index++)
    {
        currentTime = workingList.pullTime(index+1);
        std::cout << "current time: " << currentTime << '\n';
        if(currentTime > highTime)
            highTime = currentTime;
        if(currentTime < lowTime)
            lowTime = currentTime;

    }
    
    std::cout << "high time: " << highTime << endl;
    std::cout << "low time: " << lowTime << endl;

//**TEMPERATURE*************************************************//


    int highScore = 1;
    int currentScore = 0;
    int currentPlayer;
    int firstPlace;
    int currentTemperature = 0;
    
    currentPlayer = workingList.pullTemperature(0);
    std::cout << "first temperature: " << currentTemperature << endl;
    for(int index = 0; index < totalEntries; index++)
    {
        currentTemperature = workingList.pullTemperature(index);
        std::cout << "current temperature: " << currentTemperature << '\n';
        if(currentTemperature == currentPlayer)
        {
            currentScore++;
            if(currentScore > highScore)
                {
                    highScore = currentScore;
                    firstPlace = currentPlayer;
                }
            
        }
        else
            currentScore = 1;
            currentPlayer = workingList.pullTemperature(index);
    }

    std::cout << "First Place: " << firstPlace << endl;
    std::cout << "High score: " << highScore << endl;

    //std::cout << "high temperature: " << highTemperature << endl;
    //std::cout << "low temperature: " << lowTemperature << endl;

//**WINDSPEED***************************************************//


    int currentWindspeed = 0;

    for(int index = 0; index < totalEntries; index++)
    {
        currentWindspeed = workingList.pullWindspeed(index);
        std::cout << "current windspeed: " << currentWindspeed << '\n';
    }
}

void datalogger::printReport(const char* label)
{
    //be sure to COUT label!!
    //workingList.printMe();
    runTheNumbers();
    return;
}







//containsTimestamp(timestamp)
























