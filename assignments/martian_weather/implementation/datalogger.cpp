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
    //std::cout << "Totals: " << totalEntries << endl;

//**TIME*******************************************************//
    
    int lowTime = 1500000000;
    int highTime = 0;
    int currentTime = 0;

    for(int index = 0; index < totalEntries; index++)
    {
        currentTime = workingList.pullTime(index+1);
        //std::cout << "current time: " << currentTime << '\n';
        if(currentTime > highTime)
            highTime = currentTime;
        if(currentTime < lowTime)
            lowTime = currentTime;

    }
    
    //std::cout << "high time: " << highTime << endl;
    //std::cout << "low time: " << lowTime << endl;

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
    
    //poorly named -- total temperatures over these intervals
    //windspeeds over intervals, added up
    int totalT0 = 0;
    int totalT1 = 0;
    int totalT2 = 0;
    int totalT3 = 0;
    int totalT4 = 0;
    int totalT5 = 0;
    int totalT6 = 0;
    int totalT7 = 0;
    int totalT8 = 0;
    int totalT9 = 0;

    //averages of each interval
    double avgT0 = 0;
    double avgT1 = 0;
    double avgT2 = 0;
    double avgT3 = 0;
    double avgT4 = 0;
    double avgT5 = 0;
    double avgT6 = 0;
    double avgT7 = 0;
    double avgT8 = 0;
    double avgT9 = 0;

    currentPlayer = workingList.pullTemperature(0);
    firstPlace = currentPlayer;
    for(index = 0; index < totalEntries; index++)
    {
        currentTemperature = workingList.pullTemperature(index);
        //std::cout << "current temperature: " << currentTemperature << '\n';


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

    for(index = 0; index < (totalEntries); index++)
    {
        currentTemperature = workingList.pullTempByTime(index);
        //DON'T TURN THIS ONE ON! FOR GET ABOUT IT
        //std::cout << "current temperature: " << currentTemperature << '\n';
        //std::cout << endl;
        caseCondition = (index)/10.0;
        std::cout << "index: " << index << "case condition: " << caseCondition;
        switch(caseCondition)
        {
            case (0):
                totalT0+= currentTemperature;
                std::cout << "currentTempHere: " << currentTemperature << endl;
                //std::cout << "0 " << totalT0 << endl;
                break;
            case (1):
                totalT1+= currentTemperature;
                std::cout << "1currentTempHere: " << currentTemperature << endl;
                //std::cout << "1 " << totalT1 << endl;
                break;
            case (2):
                totalT2+= currentTemperature;
                std::cout << "2currentTempHere: " << currentTemperature << endl;
                //std::cout << "2 " << totalT2 << endl;
                break;
            case (3):
                //totalT3+= currentTemperature;
                ////std::cout << "3 " << totalT3 << endl;
                break;
            case (4):
                //totalT4+= currentTemperature;
                //std::cout << "4 " << totalT4 << endl;
                break;
            case (5):
                //totalT5+= currentTemperature;
                //std::cout << "5 " << totalT5 << endl;
                break;
            case (6):
                //totalT6+= currentTemperature;
                //std::cout << "6 " << totalT6 << endl;
                break;
            case (7):
                //totalT7+= currentTemperature;
                //std::cout << "7 " << totalT7 << endl;
                break;
            case (8):
                //totalT8+= currentTemperature;
                //std::cout << "8 " << totalT8 << endl;
                break;
            case (9):
                //totalT9+= currentTemperature;
                //std::cout << "9 " << totalT9 << endl;
                break;
        } 
    }
    avgT0 = totalT0 / 10.0;
    avgT1 = totalT1 / 10.0;
    avgT2 = totalT2 / 10.0;
    avgT3 = totalT3 / 10.0;
    avgT4 = totalT4 / 10.0;
    avgT5 = totalT5 / 10.0;
    avgT6 = totalT6 / 10.0;
    avgT7 = totalT7 / 10.0;
    avgT8 = totalT8 / 10.0;
    avgT9 = totalT9 / 10.0;

    std::cout << "avgT0: " << avgT0 << endl;
    std::cout << "avgT1: " << avgT1 << endl;
    std::cout << "avgT2: " << avgT2 << endl;
    std::cout << "avgT3: " << avgT3 << endl;
    std::cout << "avgT4: " << avgT4 << endl;
    std::cout << "avgT5: " << avgT5 << endl;
    std::cout << "avgT6: " << avgT6 << endl;
    std::cout << "avgT7: " << avgT7 << endl;
    std::cout << "avgT8: " << avgT8 << endl;
    std::cout << "avgT9: " << avgT9 << endl;
    std::cout << "all of avg0: " << totalT0 << endl;
    std::cout << "all of avg1: " << totalT1 << endl;
    std::cout << "all of avg2: " << totalT2 << endl;


    //std::cout << "First Place: " << firstPlace << endl;
    //std::cout << "High score: " << highScore << endl;
    //std::cout << "Belowneg50 " << belowneg50 << endl;
    //std::cout << "above0 " << above0 << endl;

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

    //windspeeds over intervals, added up
    int totalw0 = 0;
    int totalw1 = 0;
    int totalw2 = 0;
    int totalw3 = 0;
    int totalw4 = 0;
    int totalw5 = 0;
    int totalw6 = 0;
    int totalw7 = 0;
    int totalw8 = 0;
    int totalw9 = 0;

    //averages of each interval
    double avgw0 = 0;
    double avgw1 = 0;
    double avgw2 = 0;
    double avgw3 = 0;
    double avgw4 = 0;
    double avgw5 = 0;
    double avgw6 = 0;
    double avgw7 = 0;
    double avgw8 = 0;
    double avgw9 = 0;

    caseCondition = 0;
    currentPlayer = workingList.pullWindspeed(0);
    firstPlace = currentPlayer;
    //std::cout << "First Windspeed: " << currentPlayer;
    for(int index = 0; index < totalEntries; index++)
    {
        currentWindspeed = workingList.pullWindspeed(index);
        //std::cout << "current windspeed: " << currentWindspeed << '\n';
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

    //int avgCounter = 0;

    //if(avgCounter <= 9)
    //{
    //    while(avgCounter <= 9)
    //    {
    //        int thisWind;
    //            
    //        thisWind = workingList.pullWindByTime(avgCounter);
    //        totalw0 += thisWind;
    //        cout << "0-9: " << avgCounter << " this value: " 
    //            << thisWind <<" total: "<< totalw0 << endl;
    //        avgCounter++;
    //    }
    //}
    //cout << "total this w: " << totalw0 << endl;

    //if(avgCounter <= 19)
    //{
    //    int thisWind;

    //    thisWind = workingList.pullWindByTime(avgCounter);
    //    totalw1 += thisWind;
    //    cout << "10-19: " << avgCounter << " this value: " 
    //        << thisWind <<" total: "<< totalw1 << endl;
    //    avgCounter++;
    //}
    //cout << "total this w: " << totalw1 << endl;

   //BECAUSE IT'S GOING BY THE LIST IN THE ORDER IN TIME! iT WAS RIGHT ALL ALONG!!!!: 
    for(int index = 0; index < (totalEntries); index++)
    {
        currentWindspeed = workingList.pullWindByTime(index);

        caseCondition = (index)/10;
        switch(caseCondition)
        {
            case (0):
                totalw0+= currentWindspeed;
                std::cout << index << " current windspeed here " << currentWindspeed << endl;
                //std::cout << "case condition: " << caseCondition << " " << endl;
                //std::cout << "0 " << totalw0 << endl;
                break;
            case (1):
                totalw1+= currentWindspeed;
                std::cout << index << "CASE 1! 1current windspeed here " << currentWindspeed << endl;
                //std::cout << "case condition: " << caseCondition << " " << endl;
                //std::cout << "1 " << totalw1 << endl;
                break;
            case (2):
                totalw2+= currentWindspeed;
                std::cout << index << "I SHOULD BE TWO 2current windspeed here " << currentWindspeed << endl;
                //std::cout << "case condition: " << caseCondition << " " << endl;
                //std::cout << "2 " << totalw2 << endl;
                break;
            case (3):
                totalw3+= currentWindspeed;
                //std::cout << "3 " << totalw3 << endl;
                break;
            case (4):
                totalw4+= currentWindspeed;
                //std::cout << "4 " << totalw4 << endl;
                break;
            case (5):
                totalw5+= currentWindspeed;
                //std::cout << "5 " << totalw5 << endl;
                break;
            case (6):
                totalw6+= currentWindspeed;
                //std::cout << "6 " << totalw6 << endl;
                break;
            case (7):
                totalw7+= currentWindspeed;
                //std::cout << "7 " << totalw7 << endl;
                break;
            case (8):
                totalw8+= currentWindspeed;
                //std::cout << "8 " << totalw8 << endl;
                break;
            case (9):
                totalw9+= currentWindspeed;
                //std::cout << "9 " << totalw9 << endl;
                break;
        } 

    }

    avgw0 = totalw0 / 10.0;
    avgw1 = totalw1 / 10.0;
    avgw2 = totalw2 / 10.0;
    avgw3 = totalw3 / 10.0;
    avgw4 = totalw4 / 10.0;
    avgw5 = totalw5 / 10.0;
    avgw6 = totalw6 / 10.0;
    avgw7 = totalw7 / 10.0;
    avgw8 = totalw8 / 10.0;
    avgw9 = totalw9 / 10.0;
//**********************************************
//SAVE ALL THIS SHIT FOR LATER!! DON'T DELETE!
    std::cout << "avgw0: " << avgw0 << endl;
    std::cout << "avgw1: " << avgw1 << endl;
    std::cout << "avgw2: " << avgw2 << endl;
    std::cout << "avgw3: " << avgw3 << endl;
    std::cout << "avgw4: " << avgw4 << endl;
    std::cout << "avgw5: " << avgw5 << endl;
    std::cout << "avgw6: " << avgw6 << endl;
    std::cout << "avgw7: " << avgw7 << endl;
    std::cout << "avgw8: " << avgw8 << endl;
    std::cout << "avgw9: " << avgw9 << endl;
    std::cout << "all of avg0: " << totalw0 << endl;
    std::cout << "all of avg1: " << totalw1 << endl;
    std::cout << "all of avg2: " << totalw2 << endl;

    //std::cout << "First Place: " << firstPlace << endl;
    //std::cout << "High score: " << highScore << endl;
    //std::cout << "zeroWind " << zeroWind << endl;
    //std::cout << "fastWind " << fastWind << endl;
}
//*************************************************

void datalogger::printReport(const char* label)
{
    //be sure to COUT label!!
    //workingList.printMe();
    runTheNumbers();
    return;
}







//containsTimestamp(timestamp)
























