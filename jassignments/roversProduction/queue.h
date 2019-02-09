#ifndef QUEUE_H
#define QUEUE_H

//#include "rover.h"
#include "resultdata.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>


using namespace std;

class queue
{

    public:
        queue();
        queue(const int& MAX_RESULTS); 
        ~queue();
        queue(const queue& otherqueue)=delete;
        //no need for copy constructor??
        bool isEmpty() const;
        void enqueue(const resultdata& dataPoint);
        resultdata dequeue();

    private:
        int front;
        int back;
        int count;
        int maxSize;
        resultdata* dataPoints = nullptr; 

};


#endif
