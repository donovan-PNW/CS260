#include "resultdata.h"
#include <iostream>

using namespace std;

resultdata::resultdata() : roverID(0), xCoordinate(0), yCoordinate(0), results(0)
{
}

resultdata::~resultdata()
{
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

void resultdata::print() const
{
    std::cout << "Rover: " << roverID << " xCoordinate: " << xCoordinate
        << " yCoordinate: " << yCoordinate << " results: " << results << endl;
}
