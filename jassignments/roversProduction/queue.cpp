#include "queue.h"
#include "resultdata.h"


using namespace std;


queue::queue(): front(0), back(1 - 1), count(0)
{
}

queue::queue(const int& MAX_RESULTS): front(0), back(MAX_RESULTS - 1), count(0), maxSize(MAX_RESULTS)
{
    dataPoints = new resultdata[MAX_RESULTS];
    


}

queue::~queue()
{
    delete [] dataPoints;
}


bool queue::isEmpty() const
{
    bool totesEmpty= false;
    if((count) == 0)
        totesEmpty= true;
    return totesEmpty;
}

void queue::enqueue(const resultdata& dataPoint)
{
    if(count < maxSize)
    {
        back = (back + 1) % maxSize;
        dataPoints[back] = dataPoint;
        //std::cout << "BEING FED IN: \n";
        //dataPoint.print();
        //std::cout << "ACTUALLY IN QUEUE: " << endl;
        //dataPoints[back].print();
        //std::cout << endl;
        //std::cout << "AT BACK = " << back << endl;
        //std::cout << "TOTAL COUNT: " << count << endl;
        //std::cout << endl << endl;
        count++;
    }
}

resultdata queue::dequeue()
{
    resultdata thisDatapoint = dataPoints[front];
    //std::cout << "BEING PULLED OUT: \n";
    //thisDatapoint.print();
    //std::cout << "AT FRONT = " << front << endl;
    //std::cout << "TOTAL COUNT: " << count << endl;
    if(!isEmpty())
    {
        front = (front+1) % maxSize;
        count--;
    }
    return thisDatapoint;
}
















