#include "weatherdata.h"
#include <iostream>
#include <iomanip>

using namespace std;

weatherdata::weatherdata():timestamp(-1), temperature(-1), windspeed(-1)
{
}

//ok, what am I doing here? I don't remember needing to set
//variables first before the actual set functions. Why can't I just punch them in?
weatherdata::weatherdata(int timestamp, int temperature, int windspeed) :
timestamp(timestamp),
temperature(temperature),
windspeed(windspeed)
{

}

//{
//    setTimestamp(timestamp);
//    setTemperature(temperature);
//    setWindspeed(windspeed);
//}

const weatherdata& weatherdata::operator=(const weatherdata& entry)
{
    //PROBABLY don't need a self copy
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


//void setTimestamp(int timestamp)
//{
//    this->timestamp = timestamp;
//}
//void setTemperature(int temperature)
//{
//    this->temperature = temperature;
//}
//void setWindspeed(int windspeed)
//{
//    this->windspeed = windspeed;
//}



//JUST DO BOOLEAN TO CHECK!!
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
    << std::setw(8) << entry.windspeed;
    return out;
}

bool operator<(const weatherdata& entry1, const weatherdata& entry2)
{
    int timestamp1;
    int timestamp2;

    timestamp1 = entry1.getTimestamp();
    timestamp2 = entry2.getTimestamp();

    if(timestamp1 > timestamp2)
        return true;
    else
        return false;
}












