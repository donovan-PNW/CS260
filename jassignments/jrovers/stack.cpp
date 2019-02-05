#include <cassert>
#include "stack.h"
using namespace std;

stack::stack() : home(nullptr), steps(0)
{
}

stack::stack(const stack& someStack)
{
    //waypoint* originalChain = someStack.home;
    if(someStack.home == nullptr)
    {
        home=nullptr; 
    }
    else
    {
        home = new waypoint;
        assert(home != nullptr);
        //would REALLY like this to be an array of 2. needs pointer to pointer though?
        
        home->xCoordinates = someStack.home->xCoordinates;
        home->yCoordinates = someStack.home->yCoordinates;
        
        waypoint* currentLocation = home;
        waypoint* sourceNode = someStack.home->next;
        //I don't need this next pointer, but I might need to set up a back one.
        //waypoint* next = someStack.home->next;
        //waypoint* back = nullptr;
        while(sourceNode != nullptr)
        {
            currentLocation->next = new waypoint;
            assert(currentLocation->next != nullptr);
            currentLocation = currentLocation->next;
            currentLocation->xCoordinates = sourceNode->xCoordinates;
            currentLocation->yCoordinates = sourceNode->yCoordinates;
            sourceNode = sourceNode->next;
        }
        currentLocation->next = nullptr;


    }

}

