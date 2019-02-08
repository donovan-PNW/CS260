#include <iostream>
#include "queue.h"
#include "resultdata.h"

using namespace std;

void dumpQueue(queue &q)
{
    cout << "Dumping the queue" << endl;
    while (!q.isEmpty())
    {
	resultdata result = q.dequeue();
	cout << "This datapoint: "<<  endl;
    result.print();
    cout << endl;
    }
}

int main()
{
    queue q;

    q.enqueue(resultdata(1,1,1,1));
    dumpQueue(q);

    q.enqueue(resultdata(1,1,1,1));
    q.enqueue(resultdata(2,2,2,2));
//    q.printInternals();
    dumpQueue(q);

    q.enqueue(resultdata(1,1,1,1));
    q.enqueue(resultdata(2,2,2,2));
    q.enqueue(resultdata(3,3,3,3));
    q.enqueue(resultdata(4,4,4,4));
    q.enqueue(resultdata(5,5,5,5));
    q.enqueue(resultdata(6,6,6,6));
//    q.printInternals();
    dumpQueue(q);
}
