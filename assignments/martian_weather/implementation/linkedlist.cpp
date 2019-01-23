#include "linkedlist.h"
//shouldn't these just be included from the header file?
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

linkedList::linkedList() : head(nullptr), listSize(0)
{
}

bool linkedList::insert(const weatherdata& thisEntry)
{
    bool yesOrNo;
    entryNode* currentTime = timeHead;
    entryNode* previousTime = nullptr;
    entryNode* currentTemperature = temperatureHead;
    entryNode* previousTemperature = nullptr;
    entryNode* currentWindspeed = windspeedHead;
    entryNode* previousWindspeed = nullptr;
    //reverse and forward?
    //ALSO: do I NEED to assert head?
    entryNode* nextNode = nullptr;
    while(currentTime != nullptr && currentTime->entry < thisEntry)
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
        //IDK how to make this triply threaded lol
        //maybe do a while loop for each nextTemp nextWind?

    }
    //while(current)
}


