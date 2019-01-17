#include "datalogger.h"
#include <iostream>
#include <iomanip>


datalogger::datalogger():timestamp(-1), temperature(-1), windspeed(-1)
{
}

//ok, what am I doing here? I don't remember needing to set
//variables first before the actual set functions. Why can't I just punch them in?
datalogger::datalogger(int timestamp, int temperature, int windspeed) :
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

const datalogger& datalogger::operator=(const datalogger& entry)
{
    //PROBABLY don't need a self copy
    setTimestamp(entry.timestamp);
    setTemperature(entry.temperature);
    setWindspeed(entry.windspeed);

}





