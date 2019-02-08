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

//ID LIKE TO TRY IT THIS WAY BUT I'M PRETTY SURE IT'S INCOMPLETE.
//NEED TO WRITE INDIVIDUAL SET FUNCTIONS FOR EACH ONE OF THESE FOR SOME REASON
//AND CALL THEM HERE
resultdata::resultdata(int newRoverID, int newXCoordinate, int newYCoordinate, int newResults)
{
    roverID = newRoverID;
    xCoordinate = newXCoordinate;
    yCoordinate = newYCoordinate;
    results = newResults;
    //or:
    //roverID(newRoverID),
    //xCoordinate(newXCoordinate),
    //yCoordinate(newYCoordinate),
    //results(newResults)
}

//OR JUST CALL PRINT BEFORE DELETING? LOL
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
    std::cout << "Rover: " << roverID << " xCoordinate: " << xCoordinate
        << " yCoordinate: " << yCoordinate << " results: " << results << endl;
}

void resultdata::setRoverID(int roverID)
{
    this->roverID = roverID;
}
void resultdata::setXCoordinate(int xCoordinate)
{
    this->xCoordinate = xCoordinate;
}
void resultdata::setYCoordinate(int yCoordinate)
{
    this->yCoordinate = yCoordinate;
}
void resultdata::setResults(int results)
{
    this->results = results;
}






























