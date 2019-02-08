#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//pg 199

struct coordinates
{
    //TODO delet this 0
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
        bool isEmpty() const;
        bool push(const coordinates& newEntry); //,const int& datastuff)
        coordinates pop();
        //make new datatype!! or do a waypoint.peek() thing
        coordinates peek() const;
        //TODO: UNNEDED
        int peekY() const;

    private:
        struct waypoint
        {
            coordinates thisWaypoint;
            waypoint * next;
            waypoint * back;
        };
            waypoint * topItem;
            int steps;

};




#endif
