#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <iostream>
#include <iomanip>
class weatherdata
{
public:
    weatherdata();
    weatherdata(int timestamp, int temperature, int windspeed);
    weatherdata(const weatherdata& entry) =delete;
    ~weatherdata();


    int getTimestamp() const;
    int getTemperature() const;
    int getWindspeed() const;

    void setTimestamp(int timestamp);
    void setTemperature(int temperature);
    void setWindspeed(int windspeed);
    
    
    const weatherdata& operator=(const weatherdata& entry);
    friend std::ostream& operator<<(std::ostream& out, const weatherdata& entry);

private:
    int timestamp;
    int temperature;
    int windspeed; 

};

//MAYBE put this into the linkedlist class?
bool operator< (const weatherdata& entry1, const weatherdata& entry2);
bool operator== (const weatherdata& entry1, const weatherdata& entry2);



#endif
