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
    
    
    const datalogger& operator=(const datalogger& entry);
    friend std::ostream& operator<<(std::ostream& out, const datalogger& entry);

private:
    int timestamp;
    int temperature;
    int windspeed; 

};

//MAYBE put this into the linkedlist class?
bool operator< (const datalogger& entry1, const datalogger& entry2);
bool operator== (const datalogger& entry1, const datalogger& entry2);



#endif
