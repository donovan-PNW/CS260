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
    struct entryNode
    {
        weatherdata thisEntry;
        entryNode* nextTime;
        entryNode* nextTemperature;
        entryNode* nextWindspeed;
    };

    entryNode* head;
    int listSize;
    

};




#endif
