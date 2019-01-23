#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstring>
#include <ostream>
#include "weatherdata.h"

class linkedList
{
public:
    linkedList();
    linkedList(const linkedList& thisList)= delete;
    ~linkedList();

    //not needed
    //const list& operator=(const list& aList);

    bool insert(const weatherdata& thisEntry);
    //indexNo?
    bool remove(const char* indexNo);
    bool retrieve(const char* indexNo, weatherdata& thisEntry) const;
    int getSize() const;

    //why not iostream???
    friend std::ostream& operator <<(std::ostream& out, const linkedList& thisList);

private:
    //question: Should I try going in both directions? that is, a backward pointer
    //AND a frontward pointer? This may go well with entryNode* middle.
    //Also conceptual question: Why are linked lists better? As in, what's a heap?
    struct entryNode
    {
        weatherdata thisEntry;
        entryNode* nextTime;
        entryNode* nextTemperature;
        entryNode* nextWindspeed;
    };

    entryNode* head;
    entryNode* middle;
    entryNode* tail;
    int listSize;
    

};




#endif
