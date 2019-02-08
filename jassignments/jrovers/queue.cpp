#include "queue.h"
#include "resultdata.h"


using namespace std;



queue::queue(): front(0), back(MAX_ENTRIES - 1), count(0)
{
}

queue::~queue()
{
    
}

bool queue::isEmpty() const
{
    return count == 0;
}

resultdata queue::enqueue(const resultdata& dataPoint)
{
    if(count < MAX_ENTRIES)
    {
        back = (back + 1) % MAX_ENTRIES;
        dataPoints[back] = dataPoint;
        count++;
        result = true;
    }
    return result;
}

resultdata queue::dequeue()
{
    bool result = false;
    
    if(!isEmpty())
    {
        front = (front+1) % MAX_ENTRIES;
        count--;
        result = true;
    }
    return result;
}

void queue::peek() const
{
    dataPoints[front].print();
}


