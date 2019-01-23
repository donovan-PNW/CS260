#include "linkedlist.h"
//shouldn't these just be included from the header file?
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

linkedList::linkedList() : timeHead(nullptr), temperatureHead(nullptr), windspeedHead(nullptr), listSize(0)
{
}

bool linkedList::insert(const weatherdata& thisEntry)
{
    bool isDuplicate;
    entryNode* currentTime = timeHead;
    entryNode* previousTime = nullptr;
    entryNode* currentTemperature = temperatureHead;
    entryNode* previousTemperature = nullptr;
    entryNode* currentWindspeed = windspeedHead;
    entryNode* previousWindspeed = nullptr;
    //reverse and forward?
    //ALSO: do I NEED to assert head?
    while(currentTime != nullptr && currentTime->entry < thisEntry)
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
        //IDK how to make this triply threaded lol
        //maybe do a while loop for each nextTemp nextWind?

    }

    if(currentTime && currentTime->entry == thisEntry)
    {
        
        //idk, just delete the old one from here right?
        //like, removeEntry() but only if you're working with the clean one?
        //Like, have it pass a boolean from datalogger.cpp?
        //if(cleanData)
        //    splice this entry out
        //
        //
        //
        //idk I might just do something here with currTemp and currWind
        //instead of using isDuplicate to scan through the list again as currTemp and currWind
        //separately
    }
    //while(current)

    //REMOVE ELSE, JUST LET IT GO STRAIGHT INTO THIS. RAWDATA WILL ADD THEM TOGETHER
    else
    {
        entryNode * newEntry = new entryNode;
        newEntry->entry = thisEntry;
        newEntry->nextTime = nullptr;
        newEntry->nextTemperature = nullptr;
        newEntry->nextWindspeed = nullptr;

        //NEED TO DO THIS FOR EACH THREAD 
        newEntry->nextTime = currentTime;
 
        if(previousTime == nullptr)
        {
            timeHead = newEntry;
            temperatureHead = newEntry;
            windspeedHead = newEntry;
        }
        else
        {
            previousTime->nextTime = newEntry;
            //NOT IN THIS PART! DO THESE SEPARATELY
            //previousTemperature->nextTemperature = newEntry;
            //previousWindspeed->nextWindspeed = newEntry;
        }

    }


    return isDuplicate;
}


