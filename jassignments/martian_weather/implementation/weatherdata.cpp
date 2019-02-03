#include "weatherdata.h"
#include <iostream>
#include <iomanip>

using namespace std;

weatherdata::weatherdata():timestamp(-1), temperature(-1), windspeed(-1)
{
}

weatherdata::weatherdata(int newTimestamp, int newTemperature, int newWindspeed) :
timestamp(newTimestamp),
temperature(newTemperature),
windspeed(newWindspeed)
{
    timestamp = newTimestamp;
    temperature = newTemperature;
    windspeed = newWindspeed;
}

const weatherdata& weatherdata::operator=(const weatherdata& entry)
{
    setTimestamp(entry.timestamp);
    setTemperature(entry.temperature);
    setWindspeed(entry.windspeed);
    return *this;

}

weatherdata::~weatherdata()
{
}

int weatherdata::getTimestamp() const
{
    return timestamp;
}
int weatherdata::getTemperature() const
{
    return temperature;
}
int weatherdata::getWindspeed() const
{
    return windspeed;
}


void weatherdata::setTimestamp(int newTimestamp)
{
    timestamp = newTimestamp;
}
void weatherdata::setTemperature(int newTemperature)
{
    temperature = newTemperature;
}
void weatherdata::setWindspeed(int newWindspeed)
{
    windspeed = newWindspeed;
}



bool operator==(const weatherdata& entry1, const weatherdata& entry2)
{
    int timestamp1;
    int timestamp2;

    timestamp1 = entry1.getTimestamp();
    timestamp2 = entry2.getTimestamp();

    if(timestamp1 == timestamp2)
        return true;
    else
        return false;

}

std::ostream& operator<<(std::ostream& out, const weatherdata& entry)
{
    out << std::setw(20) << entry.timestamp
    << std::setw(15) << entry.temperature
    << std::setw(8) << entry.windspeed
    << '\n';
    return out;
}

//bool operator<(const weatherdata& entry1, const weatherdata& entry2)
//{
//    int timestamp1;
//    int timestamp2;
//
//    timestamp1 = entry1.getTimestamp();
//    timestamp2 = entry2.getTimestamp();
//
//    if(timestamp1 > timestamp2)
//        return true;
//    else
//        return false;
//}












