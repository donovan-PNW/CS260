#include <iostream>
#include "rover.h"
#include "scandata.h"
#include "queue.h"

using namespace std;

rover::rover(): ID(0), xCoordinate(0), yCoordinate(0), results(0) 
{
}

rover::rover(const int& newID, const int& MAX_RESULTS, queue& theResultqueue)
{
    ID = newID;
    resultsPointer = &theResultqueue;
}

rover::~rover()
{
}

void rover::deploy()
{
    std::cout << "Rover (" << ID << ") deploying..." << endl;
    std::cout << "Rover (" << ID << ") ready" << endl;
}

void rover::move(const int& newX, const int& newY)
{
    xCoordinate = newX;
    yCoordinate = newY;
}

void rover::corescan()
{
    std::cout << "Rover (" << ID << ") scanning.";
    //when to use static???
    results = scandata::getScandata(xCoordinate,yCoordinate);
    thisDatapoint.setRoverID(ID);
    thisDatapoint.setXCoordinate(xCoordinate);
    thisDatapoint.setYCoordinate(yCoordinate);
    thisDatapoint.setResults(results);
    resultsPointer.enqueue(thisDatapoint);
    //resultsPointer->enqueue(thisDatapoint);
     
    

}

void rover::dock()
{

}













