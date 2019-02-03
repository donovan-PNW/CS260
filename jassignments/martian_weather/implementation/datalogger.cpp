#include "datalogger.h"
#include <iostream>
#include <iomanip>

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

    lowTime = 0;
    highTime = 0;
    belowneg50 = 0;
    above0 = 0;
    mostCommonTemperature = 0;
    zeroWind = 0;
    fastWind = 0;
    mostCommonWind = 0;
    totalEntries = 0;


    //avgT 0-9 
    //avgW 0-9

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
    totalEntries = 0;
 
    totalEntries = workingList.totalizer()-1 ;
    //WHY DO I NEED TO SHIFT THIS TO GET IT TO WORK?

//**TIME*******************************************************//
    
    lowTime = 1500000000;
    highTime = 0;
    int currentTime = 0;

    for(int index = 0; index < totalEntries; index++)
    {
        currentTime = workingList.pullTime(index+1);
        if(currentTime > highTime)
            highTime = currentTime;
        if(currentTime < lowTime)
            lowTime = currentTime;
    }

//**TEMPERATURE*************************************************//


    belowneg50 = 0;
    above0 = 0;
    int highScore = 0;
    int currentScore = 0;
    int currentPlayer = 0;
    int firstPlace;
    double currentTemperature = 0;
    int caseCondition = 0;
    int index = 0;
    
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
    avgT0 = 0;
    avgT1 = 0;
    avgT2 = 0;
    avgT3 = 0;
    avgT4 = 0;
    avgT5 = 0;
    avgT6 = 0;
    avgT7 = 0;
    avgT8 = 0;
    avgT9 = 0;

    currentPlayer = workingList.pullTemperature(0);
    firstPlace = currentPlayer;
    for(index = 1; index < totalEntries+1; index++)
    {
        currentTemperature = workingList.pullTemperature(index);

        if(currentTemperature < (-500))
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
        {
            currentScore = 0;
           currentPlayer = workingList.pullTemperature(index + 1);
        }
        
    }

    for(index = 0; index < (totalEntries); index++)
    {
        currentTemperature = workingList.pullTemperature(index + 1);
        caseCondition = (index)/1000;
        switch(caseCondition)
        {
            case (0):
                totalT0+= currentTemperature;
                break;
            case (1):
                totalT1+= currentTemperature;
                break;
            case (2):
                totalT2+= currentTemperature;
                break;
            case (3):
                totalT3+= currentTemperature;
                break;
            case (4):
                totalT4+= currentTemperature;
                break;
            case (5):
                totalT5+= currentTemperature;
                break;
            case (6):
                totalT6+= currentTemperature;
                break;
            case (7):
                totalT7+= currentTemperature;
                break;
            case (8):
                totalT8+= currentTemperature;
                break;
            case (9):
                totalT9+= currentTemperature;
                break;
        } 
    }
    avgT0 = totalT0 / 1000.0;
    avgT1 = totalT1 / 1000.0;
    avgT2 = totalT2 / 1000.0;
    avgT3 = totalT3 / 1000.0;
    avgT4 = totalT4 / 1000.0;
    avgT5 = totalT5 / 1000.0;
    avgT6 = totalT6 / 1000.0;
    avgT7 = totalT7 / 1000.0;
    avgT8 = totalT8 / 1000.0;
    avgT9 = totalT9 / 1000.0;


    mostCommonTemperature = firstPlace / 10.;


//**WINDSPEED***************************************************//

    //these are for if you make it into a separate function
    highScore = 0;
    currentScore = 0;
    currentPlayer = 0;
    firstPlace = 0;
    currentScore = 0;

    zeroWind = 0;
    fastWind = 0;
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
    avgW0 = 0;
    avgW1 = 0;
    avgW2 = 0;
    avgW3 = 0;
    avgW4 = 0;
    avgW5 = 0;
    avgW6 = 0;
    avgW7 = 0;
    avgW8 = 0;
    avgW9 = 0;

    caseCondition = 0;
    currentWindspeed= workingList.pullWindspeed(0);
    firstPlace = currentPlayer;
    for(index = 0; index < totalEntries; index++)
    {
        currentWindspeed= workingList.pullWindspeed(index);

        if(currentWindspeed == 0)
        {
            zeroWind++;
        }
        if(currentWindspeed >= 2500)
        {
            fastWind++;
        }
        if(currentWindspeed == currentPlayer)
        {
            currentScore++;
            if(currentScore > highScore)
            {
                highScore = currentScore;
                firstPlace = currentPlayer;
            }
            
        }
        else
        {
            //DO NOT TOUCH ME!!!
            currentScore = 0;
            currentPlayer = workingList.pullWindspeed(index+1);
        }

        
    }
    for(int index = 0; index < (totalEntries); index++)
    {
        currentWindspeed = workingList.pullWindspeed(index + 1);

        caseCondition = (index)/1000.0;
        switch(caseCondition)
        {
            case (0):
                totalw0+= currentWindspeed;
                break;
            case (1):
                totalw1+= currentWindspeed;
                break;
            case (2):
                totalw2+= currentWindspeed;
                break;
            case (3):
                totalw3+= currentWindspeed;
                break;
            case (4):
                totalw4+= currentWindspeed;
                break;
            case (5):
                totalw5+= currentWindspeed;
                break;
            case (6):
                totalw6+= currentWindspeed;
                break;
            case (7):
                totalw7+= currentWindspeed;
                break;
            case (8):
                totalw8+= currentWindspeed;
                break;
            case (9):
                totalw9+= currentWindspeed;
                break;
        } 

    }
    int denominator = totalEntries / 10;

    avgW0 = totalw0 / denominator;
    avgW1 = totalw1 / denominator;
    avgW2 = totalw2 / denominator;
    avgW3 = totalw3 / denominator;
    avgW4 = totalw4 / denominator;
    avgW5 = totalw5 / denominator;
    avgW6 = totalw6 / denominator;
    avgW7 = totalw7 / denominator;
    avgW8 = totalw8 / denominator;
    avgW9 = totalw9 / denominator;
    mostCommonWind = firstPlace;
}
//*************************************************

void datalogger::printReport(const char* label)
{
    runTheNumbers();


    
//FEEDBACK PLEASE I CAN'T GET SETW TO WORK RIGHT WHY DON'T THEY HAVE THE SAME PARAMETER /VALUES?,
    std::cout << std::setw(50) << "-- Data Report (" << label <<") --" << endl;
    std::cout << left << "Time range: " << right << setw(22) << lowTime << " - " <<  highTime << endl;
    std::cout << left << setw(30) << "number of entries" << right << setw(30) << totalEntries +1 << endl; 
    std::cout << left << setw(5) << "Number of entries with < -50C temperature" << right << setw(19) << belowneg50 << endl;
    std::cout << left << std::setw(30) << "Number of entries with > 0C temperature" << std::fixed << std::right << std::setw(21) << above0 << endl;
    std::cout << left << setw(30) << "most common temperature" << right <<  fixed << setprecision(1) << setw(30)  << mostCommonTemperature << endl;
    std::cout << endl;
    std::cout << left << setw(20) <<"number of entries with 0 windspeed" << right << setw(26) << zeroWind << endl;
    std::cout << left << setw(5) <<"number of entries with >25 m/s windspeed" << right << setw(20) << fastWind << endl;
    std::cout << left << setw(30) <<"most common windspeed" << right << setw(30) << mostCommonWind << endl;
    std::cout << endl;
    
    std::cout << "Average temperature over ranges" << endl;
    std::cout << "0 through 999" << setw(10) << avgT0 << endl;
    std::cout << "1000 through 1999" << setw(10) << avgT1 << endl;
    std::cout << "2000 through 2999" << setw(10) << avgT2 << endl;
    std::cout << "3000 through 3999" << setw(10) << avgT3 << endl;
    std::cout << "4000 through 4999" << setw(10) << avgT4 << endl;
    std::cout << "5000 through 5999" << setw(10) << avgT5 << endl;
    std::cout << "6000 through 6999" << setw(10) << avgT6 << endl;
    std::cout << "7000 through 7999" << setw(10) << avgT7 << endl;
    std::cout << "8000 through 8999" << setw(10) << avgT8 << endl;
    std::cout << "9000 through 9999" << setw(10) << avgT9 << endl;
    std::cout << endl;

    std::cout << "Average windspeed over ranges" << endl;
    std::cout << "0 through 999" << setw(11) << avgW0 << endl;
    std::cout << "1000 through 1999" << setw(11) << avgW1 << endl;
    std::cout << "2000 through 2999" << setw(11) << avgW2 << endl;
    std::cout << "3000 through 3999" << setw(11) << avgW3 << endl;
    std::cout << "4000 through 4999" << setw(11) << avgW4 << endl;
    std::cout << "5000 through 5999" << setw(11) << avgW5 << endl;
    std::cout << "6000 through 6999" << setw(11) << avgW6 << endl;
    std::cout << "7000 through 7999" << setw(11) << avgW7 << endl;
    std::cout << "8000 through 8999" << setw(11) << avgW8 << endl;
    std::cout << "9000 through 9999" << setw(11) << avgW9 << endl;



    return;
}


bool datalogger::containsTimestamp(int timestamp) const
{
    bool does = false;

    does = workingList.timeComparison(timestamp); 

    return does;
}
    

void datalogger::removeData(int timestamp)
{
    workingList.deleteNode(timestamp); 
    totalEntries--;
    return;
}



