#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <iostream>
class datalogger
{
public:
    datalogger();
    datalogger(int timestamp, int temperature, int windspeed);
    datalogger(const datalogger& entry) =delete;
    ~datalogger();


    int getTimestamp() const;
    int getTemperature() const;
    int getWindspeed() const;

    void setTimestamp(int timestamp);
    void setTemperature(int temperature);
    void setWindspeed(int windspeed);
    
    
    const datalogger& operator=(const datalogger& aDataLogger);




};



#endif
