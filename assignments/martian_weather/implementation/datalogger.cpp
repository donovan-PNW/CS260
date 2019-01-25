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

//just take everything and put it right into addData?
//is it getting these numbers straight from the weatherlog.cpp file?
//Or are they from t/t/w variables above inside class?
void datalogger::addData(const int timestamp, const int temperature, const int windspeed)
{
    currentEntry.setTimestamp(timestamp);
    std::cout << timestamp << endl;
    currentEntry.setTemperature(temperature);
    currentEntry.setWindspeed(windspeed);
    //int printer = currentEntry.getTimestamp();

}




//containsTimestamp(timestamp)
//
//

// &? Like, can I pass datalogger thisList by reference? also -- const?
//for example: 
//reporterShell(datalogger& tempList, char rawOrCleanString)
//{
//    datalogger thisList = tempList
//
//linkedList::createReport(datalogger& thisList, char[] rawOrCleanString) const
//createReport(thisList)
//}

// I DO NEED A COPY CONSTRUCTOR !!! :(
//
