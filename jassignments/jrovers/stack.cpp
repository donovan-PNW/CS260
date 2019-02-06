#include <cassert>
#include "stack.h"
using namespace std;

stack::stack() : topItem(nullptr), steps(0)
{
}

stack::stack(const stack& someStack)
{
    //waypoint* originalChain = someStack.topItem;
    if(someStack.topItem == nullptr)
    {
        topItem=nullptr; 
    }
    else
    {
        topItem = new waypoint;
        assert(topItem != nullptr);
        //would REALLY like this to be an array of 2. needs pointer to pointer though?
        
        topItem->xCoordinate = someStack.topItem->xCoordinate;
        topItem->yCoordinate = someStack.topItem->yCoordinate;
        
        waypoint* currentLocation = topItem;
        waypoint* sourceNode = someStack.topItem->next;
        //I don't need this next pointer, but I might need to set up a back one.
        //waypoint* next = someStack.topItem->next;
        //waypoint* back = nullptr;
        while(sourceNode != nullptr)
        {
            currentLocation->next = new waypoint;
            assert(currentLocation->next != nullptr);
            currentLocation = currentLocation->next;
            currentLocation->xCoordinate = sourceNode->xCoordinate;
            currentLocation->yCoordinate = sourceNode->yCoordinate;
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
        topItem->xCoordinate = someStack.topItem->xCoordinate;

        waypoint * currentLocation = topItem;
        waypoint * sourceNode = someStack.topItem->next;
        while(sourceNode)
        {
            currentLocation->next = new waypoint;
            assert(currentLocation->next);
            currentLocation = currentLocation->next;
            currentLocation->xCoordinate = sourceNode->xCoordinate;
            currentLocation->yCoordinate = sourceNode->yCoordinate;
            sourceNode = sourceNode->next;
        }
        currentLocation->next = nullptr;
    }
    return *this;
    }
}

stack::~stack()
{
    //IT'S ACTUALLY THIS ACCORDING TO BOOK
    //while(!isEmpty())
    //pop();
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
    return topItem == nullptr;
}

bool stack::push(const int& newXCoordinate, const int& newYCoordinate) 
{
    waypoint* newLocation = new waypoint;
    newLocation->xCoordinate = newXCoordinate;
    newLocation->yCoordinate = newYCoordinate;
    newLocation->next = topItem;
    topItem = newLocation;
    
    return true;

}

bool stack::pop()
{
    bool yesPop = false;
    if(!isEmpty())
    {
        waypoint * backFrom = topItem;
        topItem = topItem->next;
        backFrom->next = nullptr;
        delete backFrom;
        backFrom = nullptr;
        yesPop = true;

    }
    return yesPop;
}



int stack::peekX() const
{
    assert(!isEmpty());
    return topItem->xCoordinate;
    //MAKE AN ARRAY[2] FOR THIS?
}


int stack::peekY() const
{
    assert(!isEmpty());
    return topItem->yCoordinate;
    //MAKE AN ARRAY[2] FOR THIS?
}












