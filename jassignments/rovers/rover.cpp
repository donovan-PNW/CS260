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
    //resultsPointer = &theResultqueue;
    experimental = &theResultqueue;
    xCoordinate = 0;
    yCoordinate = 0;
    results = 0;
}

rover::~rover()
{
}

void rover::deploy()
{
    std::cout << "Rover (ID "<< ID << ") deploying..." << endl;
    std::cout << "Rover (ID "<< ID << ") ready" << endl;
}

void rover::move(const int& newX, const int& newY)
{
    xCoordinate = newX;
    yCoordinate = newY;
    entry.x = xCoordinate;
    entry.y = yCoordinate;
    std::cout << "Rover (ID "<< ID << ") moving to location"
    << xCoordinate << ", " << yCoordinate << "." << endl;
    roverStack.push(entry);
}

void rover::corescan()
{
    std::cout << "Rover (ID "<< ID << ") scanning.";
    std::cout << endl;
    //when to use static???
    results = scandata::getScandata(xCoordinate,yCoordinate);
    thisDatapoint.setRoverID(ID);
    thisDatapoint.setXCoordinate(xCoordinate);
    thisDatapoint.setYCoordinate(yCoordinate);
    thisDatapoint.setResults(results);
    //std::cout << "rover thisDatapoint: ";
    //thisDatapoint.print();
    //std::cout << endl;
    //TODO: idk EVEN KNOW:w
    experimental->enqueue(thisDatapoint);
    //experimental->printah();
    //resultsPointer->enqueue(thisDatapoint);

    
    //resultsPointer->enqueue(thisDatapoint);
     
    

}

void rover::dock()
{
    std::cout << "Rover (ID " << ID << ") returning to base.";
    entry = roverStack.pop();
    while(!roverStack.isEmpty())
    {
        std::cout << "Rover (ID " << ID << ") moving to location " << entry.x << ", " << entry.y << endl; 
        entry = roverStack.pop();
    }

    entry.x = 0;
    entry.y = 0;
    //sloppy
        std::cout << "Rover (ID " << ID << ") moving to location " << entry.x << ", " << entry.y << endl; 
    roverStack.push(entry);

    std::cout << "Rover (ID "<< ID << ") at base and docked" << endl;;

}













