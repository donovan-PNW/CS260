#include "resultdata.h"
#include <iostream>

using namespace std;

resultdata::resultdata() : roverID(0), xCoordinate(0), yCoordinate(0), results(0)
{
}

resultdata::~resultdata()
{
}

resultdata::resultdata(const resultdata& otherResultdata)
{
    setRoverID(otherResultdata.roverID);
    setXCoordinate(otherResultdata.xCoordinate);
    setYCoordinate(otherResultdata.yCoordinate);
    setResults(otherResultdata.results);
}

resultdata::resultdata(int newRoverID, int newXCoordinate, int newYCoordinate, int newResults)
{
    roverID = newRoverID;
    xCoordinate = newXCoordinate;
    yCoordinate = newYCoordinate;
    results = newResults;
}

const resultdata& resultdata::operator=(const resultdata& otherResultdata)
{
    if(this== &otherResultdata)
        return *this;

    else
    {
        setRoverID(otherResultdata.roverID);
        setXCoordinate(otherResultdata.xCoordinate);
        setYCoordinate(otherResultdata.yCoordinate);
        setResults(otherResultdata.results);
        return *this;
    }
}



void resultdata::print() const
{
    std::cout << "Reading from rover #" << roverID << " at "
    << xCoordinate << ", " << yCoordinate << " is " << results << endl;
}

void resultdata::setRoverID(int newRoverID)
{
    roverID = newRoverID;
}
void resultdata::setXCoordinate(int newXCoordinate)
{
    xCoordinate = newXCoordinate;
}
void resultdata::setYCoordinate(int newYCoordinate)
{
    yCoordinate = newYCoordinate;
}
void resultdata::setResults(int newResults)
{
    results = newResults;
}






























