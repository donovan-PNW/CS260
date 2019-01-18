#include <iostream>
#include <fstream>
#include"weatherdata.h"

class datalogger
{
public:
    datalogger();
    datalogger(int timestamp, int temperature, int windspeed);
    datalogger(const datalogger& datalogger)=delete;
    ~datalogger();
    

    addData();
    removeData();
    printReport();

}

