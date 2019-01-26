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
    void createReport() const;
    int getSize() const;
    void printMe() const;

    //why not iostream???
    friend std::ostream& operator <<(std::ostream& out, const linkedList& thisList);

private:
    struct entryNode
    {
        weatherdata entry;
        entryNode* nextTime;
        entryNode* nextTemperature;
        entryNode* nextWindspeed;
    };

    entryNode* timeHead;
    entryNode* temperatureHead;
    entryNode* windspeedHead;
    int listSize;
    

};




#endif
