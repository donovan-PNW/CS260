#include "queue.h"
#include "resultdata.h"


using namespace std;


queue::queue(): front(0), back(1 - 1), count(0)
{
}

//PROLLY DON'T NEED THE FIRST ONE
queue::queue(const int& MAX_RESULTS): front(0), back(MAX_RESULTS - 1), count(0), maxSize(MAX_RESULTS)
{
    //testArray = new int[MAX_RESULTS];
    dataPoints = new resultdata[MAX_RESULTS];
    


    //for(int i= 0; i<MAX_RESULTS; i++)
    //{
    //    resultdata initData();
    //    resultdata[i] = initData;
    //    
    //}
}
//queue::queue(const queue& otherqueue)
//{
//
//}

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

void queue::enqueue(const resultdata& dataPoint)//resultdata& dataPoint)
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
    else
    {
        std::cout << "queue full! Cannot accept any extra data points until items at the front of the queue are dequeued." << endl;
    }
   
}

//OR JUST VOID FUNCTION AND CALL PRINT BEFORE DELETING??
//resultdata queue::dequeue()
resultdata queue::dequeue()
{
    //OK. Why isn't this just dataPoints[front]; ?
    resultdata thisDatapoint = dataPoints[front];
    //std::cout << "BEING PULLED OUT: \n";
    //thisDatapoint.print();
    //std::cout << "AT FRONT = " << front << endl;
    //std::cout << "TOTAL COUNT: " << count << endl;
    //if(!isEmpty())
    //{
    front = (front+1) % maxSize;
    count--;
    //}
    return thisDatapoint;
}

void queue::printah() const
{
    int frontah = front;
    while(frontah <= count)
    {
        dataPoints[frontah].print();
        std::cout << "frontah: " << frontah << "diana" << endl;
        frontah++;
    }
}















