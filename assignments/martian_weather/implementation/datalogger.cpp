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
    int caseCondition = 0;
    int index = 0;
    
    currentPlayer = workingList.pullTemperature(0);
    firstPlace = currentPlayer;
    for(index = 0; index < totalEntries; index++)
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
            //DO NOT TOUCH ME!!!
            currentScore = 1;
        currentPlayer = workingList.pullTemperature(index);
        
    }

    for(index = 0; index < totalEntries; index++)
    {
        caseCondition = (index)/10;
        switch(caseCondition)
        {
            case (0):
                std::cout << "0" << endl;
                break;
            case (1):
                std::cout << "1" << endl;
                break;
            case (2):
                std::cout << "2" << endl;
                break;
            case (3):
                std::cout << "3" << endl;
                break;
            case (4):
                std::cout << "4" << endl;
                break;
            case (5):
                std::cout << "5" << endl;
                break;
            case (6):
                std::cout << "6" << endl;
                break;
            case (7):
                std::cout << "7" << endl;
                break;
            case (8):
                std::cout << "8" << endl;
                break;
            case (9):
                std::cout << "9" << endl;
                break;
        }
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
    int avg0 = 0;
    int avg1 = 0;
    int avg2 = 0;
    int avg3 = 0;
    int avg4 = 0;
    int avg5 = 0;
    int avg6 = 0;
    int avg7 = 0;
    int avg8 = 0;
    int avg9 = 0;

    caseCondition = 0;
    currentPlayer = workingList.pullWindspeed(0);
    firstPlace = currentPlayer;
    //std::cout << "First Windspeed: " << currentPlayer;
    for(int index = 0; index < totalEntries; index++)
    {
        currentWindspeed = workingList.pullWindspeed(index);
        std::cout << "current windspeed: " << currentWindspeed << '\n';
    
    //change this number when passing to production
    //THIS NEEDS TO BE UNDER TIMEHEAD, NOT WINDHEAD
    //CHECK THE WRITTEN FUNCTIONS FOR IT!!
        caseCondition = (index)/10;
        switch(caseCondition)
        {
            case (0):
                avg0+= currentWindspeed;
                std::cout << "0 " << avg0 << endl;
                break;
            case (1):
                std::cout << "1" << endl;
                avg0+= currentWindspeed;
                break;
            case (2):
                std::cout << "2" << endl;
                avg0+= currentWindspeed;
                break;
            case (3):
                std::cout << "3" << endl;
                avg0+= currentWindspeed;
                break;
            case (4):
                std::cout << "4" << endl;
                avg0+= currentWindspeed;
                break;
            case (5):
                std::cout << "5" << endl;
                avg0+= currentWindspeed;
                break;
            case (6):
                std::cout << "6" << endl;
                avg0+= currentWindspeed;
                break;
            case (7):
                std::cout << "7" << endl;
                avg0+= currentWindspeed;
                break;
            case (8):
                std::cout << "8" << endl;
                avg0+= currentWindspeed;
                break;
            case (9):
                std::cout << "9" << endl;
                avg0+= currentWindspeed;
                break;
        } 

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
            //DO NOT TOUCH ME!!!
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
























