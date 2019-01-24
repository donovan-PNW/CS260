//OI!!! YOU NEED TO OVERLOAD ASSIGNMENT OPERATOR FOR POINTER CLASSES
//
//
//
#include "linkedlist.h"
//TODO 8: shouldn't these just be included from the header file?
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
    //TODO 7:
    //reverse and forward?
    //ALSO: do I NEED to assert head?
    while(currentTime != nullptr && currentTime->entry.getTimestamp() <= thisEntry.getTimestamp())
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
        //IDK how to make this triply threaded lol
        //maybe do a while loop for each nextTemp nextWind?

    }

    if(currentTime && currentTime->entry.getTimestamp() == thisEntry.getTimestamp())
    {
        isDuplicate = true; 
        
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

    //TODO 6: I'm guessing I should just have it plow straight through without the if question?
    //OR would I be able to just use isDuplicate in some way?
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
        }
        else
        {
            previousTime->nextTime = newEntry;
            //NOT IN THIS PART! DO THESE SEPARATELY
            //previousTemperature->nextTemperature = newEntry;
            //previousWindspeed->nextWindspeed = newEntry;
        }
        
    while(currentTemperature != nullptr && currentTemperature->entry.getTemperature() < thisEntry.getTemperature())
    {
        previousTemperature = currentTemperature;
        currentTemperature = currentTemperature->nextTemperature;
    }
        if(previousTemperature == nullptr)
        {
            temperatureHead = newEntry;
        }
        else
        {
            previousTemperature->nextTemperature = newEntry;
        }
    while(currentWindspeed != nullptr && currentWindspeed->entry.getWindspeed() <= thisEntry.getWindspeed())
    {
        previousWindspeed = currentWindspeed;
        currentWindspeed = currentWindspeed->nextWindspeed;
    }
        if(previousWindspeed == nullptr)
        {
            windspeedHead = newEntry;
        }
        else
        {
            previousWindspeed->nextWindspeed = newEntry;
        }

    }


    listSize++;
    return isDuplicate;
}

//TODO 5 same qustion about createReport. what would this look like?
//bool?
//hey wait. Should I just pass createReport(list, clean or dirty all the way up from createReport)?
void linkedList::createReport() const
{
    entryNode* currentTime;
    entryNode* currentTemperature;
    entryNode* currentWindspeed;

    for(currentTime = timeHead; currentTime; currentTime = currentTime->nextTime)
    {
                
    }
}




















//bool remove
//I THINK i CAN GET AWAY WITH JUST HAVING INSERT() REPLACE ALL OF THE VALUES IN AN EXISTING LIST
//BUT I WILL NEED TO DO A SCAN AFTERWARD AS A SUBROUTINE TO FIND PROPER PLACES FOR TEMPERATURE AND WINDSPEED. just like above except first you should link previous to oldnode->next 

//EDIT: seriously? for every goddamn pass I need to use the removeData function from weatherlog.cpp
//so I do need two write this. what the fuck bro.


























