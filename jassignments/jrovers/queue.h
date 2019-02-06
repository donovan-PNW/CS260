#ifndef QUEUE_H
#define QUEUE_H

#include "rover.h"
#include "resultdata.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>


using namespace std;

//USE THE VALUE FROM IN THE MAIN DRIVER DUDE!
const int MAX_ENTRIES = 50;

class queue
{
    private:
        resultdata dataPoints[MAX_ENTRIES];
        int front;
        int back;
        int count;

    public:

        queue();
        //no need for copy constructor or destructor????
        bool isEmpty() const;
        bool enqueue(const resultdata& dataPoint);
        bool dequeue();
        void peek() const;

};



#endif
