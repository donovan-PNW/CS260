#ifndef QUEUE_H
#define QUEUE_H

//#include "rover.h"
#include "resultdata.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>


using namespace std;

//USE THE VALUE FROM IN THE MAIN DRIVER DUDE!
//FUCK IT! WE'LL DO IT LIVE
const int MAX_ENTRIES = 128;

class queue
{

    public:
        queue();
        queue(const int& MAX_RESULTS); 
        ~queue();
        //queue(const queue& otherqueue)=delete;
        //no need for copy constructor or destructor????
        bool isEmpty() const;
        void enqueue(const resultdata& dataPoint);
        resultdata dequeue();
        void printah() const;

    private:
        int front;
        int back;
        int count;
        int size;
        resultdata dataPoints[MAX_ENTRIES]; 

};



#endif
