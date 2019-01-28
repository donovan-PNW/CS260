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
    int totalEntries = 0;
    int mostCommonTemperature = 0;
    int mostCommonWindspeed = 0;

 
    totalEntries = workingList.totalizer() - 1;
    //WHY DO I NEED TO SHIFT THIS TO GET IT TO WORK?
    std::cout << "Totals: " << totalEntries << endl;

//**TIME*******************************************************//
    
    int lowTime = 1500000000;
    int highTime = 0;
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


    int belowneg50 = 0;
    int above0 = 0;
    int highScore = 0;
    int currentScore = 1;
    int currentPlayer = 0;
    int firstPlace;
    int currentTemperature = 0;
    
    currentPlayer = workingList.pullTemperature(0);
    firstPlace = currentPlayer;
    for(int index = 0; index < totalEntries; index++)
    {
        currentTemperature = workingList.pullTemperature(index);
        std::cout << "current temperature: " << currentTemperature << '\n';
        if(currentTemperature < (-50))
        {
            belowneg50++;
        }
        if(currentTemperature > 0)
        {
            above0++;
        }
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
    std::cout << "Belowneg50 " << belowneg50 << endl;
    std::cout << "above0 " << above0 << endl;

    //std::cout << "high temperature: " << highTemperature << endl;
    //std::cout << "low temperature: " << lowTemperature << endl;

//**WINDSPEED***************************************************//

    //these are for if you make it into a separate function
    highScore = 0;
    currentScore = 1;
    currentPlayer = 0;
    firstPlace = 0;
    currentScore = 0;

    int zeroWind = 0;
    int fastWind = 0;
    int currentWindspeed = 0;
    currentPlayer = workingList.pullWindspeed(0);
    firstPlace = currentPlayer;
    //std::cout << "First Windspeed: " << currentPlayer;
    for(int index = 0; index < totalEntries; index++)
    {
        currentWindspeed = workingList.pullWindspeed(index);
        std::cout << "current windspeed: " << currentWindspeed << '\n';
        if(currentWindspeed == 0)
        {
            zeroWind++;
        }
        if(currentWindspeed > 25)
        {
            fastWind++;
        }
        if(currentWindspeed == currentPlayer)
            
            currentScore++;
            if(currentScore > highScore)
            {
                highScore = currentScore;
                firstPlace = currentPlayer;
            }
        else
            currentScore = 1;
        currentPlayer = workingList.pullWindspeed(index);
            
    }
    std::cout << "First Place: " << firstPlace << endl;
    std::cout << "High score: " << highScore << endl;
    std::cout << "zeroWind " << zeroWind << endl;
    std::cout << "fastWind " << fastWind << endl;
}

void datalogger::printReport(const char* label)
{
    //be sure to COUT label!!
    //workingList.printMe();
    runTheNumbers();
    return;
}







//containsTimestamp(timestamp)
























