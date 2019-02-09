#include <cassert>
#include <iostream>
#include "rover.h"
using namespace std;

stack::stack() : topItem(nullptr), steps(0)
{
}

stack::stack(const stack& someStack)
{
    if(someStack.topItem == nullptr)
    {
        topItem=nullptr; 
    }
    else
    {
        topItem = new waypoint;
        assert(topItem != nullptr);
        topItem->thisWaypoint = someStack.topItem->thisWaypoint;
        waypoint* currentLocation = topItem;
        waypoint* sourceNode = someStack.topItem->next;
        while(sourceNode != nullptr)
        {
            currentLocation->next = new waypoint;
            assert(currentLocation->next != nullptr);
            currentLocation = currentLocation->next;
            currentLocation->thisWaypoint = sourceNode->thisWaypoint;
            sourceNode = sourceNode->next;
        }
        currentLocation->next = nullptr;


    }

}

const stack& stack::operator= (const stack& someStack)
{
    if(this == &someStack)
        return *this;
    else
    {
        waypoint * currentLocation = topItem;
        while(topItem);
        {
            currentLocation = currentLocation->next;
            delete topItem;
            topItem = currentLocation;
        }
    
    if(someStack.topItem == nullptr)
    {
        topItem = nullptr;
    }
    else
    {
        topItem = new waypoint;
        assert(topItem != nullptr);
        topItem->thisWaypoint = someStack.topItem->thisWaypoint;

        waypoint * currentLocation = topItem;
        waypoint * sourceNode = someStack.topItem->next;
        while(sourceNode)
        {
            currentLocation->next = new waypoint;
            assert(currentLocation->next);
            currentLocation = currentLocation->next;
            currentLocation->thisWaypoint = sourceNode->thisWaypoint;
            sourceNode = sourceNode->next;
        }
        currentLocation->next = nullptr;
    }
    return *this;
    }
}

stack::~stack()
{
    waypoint * currentLocation = topItem;
    while(topItem)
    {
        currentLocation = topItem->next;
        delete topItem;
        topItem = currentLocation;
    }
}

bool stack::isEmpty() const
{
    bool isEmpty = true;
    if(topItem)
        isEmpty = false;

    return isEmpty;
}

bool stack::push(const coordinates& newEntry) 
{
    waypoint* newLocation = new waypoint;
    newLocation->thisWaypoint = newEntry;
    newLocation->next = topItem;
    topItem = newLocation;
    
    return true;

}

coordinates stack::pop()
{
    coordinates theseCoordinates;
    theseCoordinates.x=0;
    theseCoordinates.y=0;

    if(!isEmpty())
    {
        theseCoordinates = topItem->thisWaypoint;
        if(topItem->next != nullptr)
        {
            waypoint * backFrom = topItem;
            topItem = topItem->next;
            backFrom->next = nullptr;
            delete backFrom;
            backFrom = nullptr;
        }
        else
        {
            delete topItem;
            topItem = nullptr;
        }

    }
    return theseCoordinates;
}



//coordinates stack::peek() const
//{
//    assert(!isEmpty());
//    return topItem->thisWaypoint;
//}

//const coordinates& stack::operator=(const coordinates& someCoordinates)
//{
//    coordinates returns
//
//}









