#ifndef STACK_H
#define STACK_H

#include "rover.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//pg 199

class stack
{
    public:
        stack();
        stack(const stack& someStack);
        ~stack();
        //SHOULD THESE BE VIRTUAL WITH A =0 OR NO VIRTUAL WITH NO =0??
        virtual bool isEmpty() const = 0;
        virtual bool push(const int& xCoordinate, const int& yCoordinate) = 0; //,const int& datastuff)
        virtual bool pop() = 0;
        //virtual rovers.peek() const = 0

    private:
        struct waypoint
        {
            int coordinates[2];
            //I guess I might need this?
            waypoint * next;
            waypoint * back;
        };
            waypoint * home;
            int steps;

};

#endif
