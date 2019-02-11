#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


struct coordinates
{
    int x = 0;
    int y = 0;
};

class stack
{
    public:
        stack();
        stack(const stack& someStack);
        ~stack();
        const stack& operator=(const stack& someStack);
        const coordinates& operator=(const coordinates& someCoordinates);
        bool isEmpty() const;
        bool push(const coordinates& newEntry); 
        coordinates pop();
        //coordinates peek() const;

    private:
        struct waypoint
        {
            coordinates thisWaypoint;
            waypoint * next;
        };
        waypoint * topItem;
        int steps;

};




#endif
