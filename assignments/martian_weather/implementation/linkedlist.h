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
    int getSize() const;
    void printMe() const;
    int totalizer() const;
    int pullTime(int target) const; 
    int pullTemperature(int target) const;
    int pullWindspeed(int target) const;
    int pullTempByTime(int target) const;
    int pullWindByTime(int target) const;
    bool timeComparison(int timestamp) const;
    void deleteNode(int timestamp);
    

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
