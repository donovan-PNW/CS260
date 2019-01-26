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

linkedList::~linkedList()
{
    entryNode* currentTime = timeHead;
    while(timeHead)
    {
        currentTime = timeHead->nextTime;
        delete timeHead;
        timeHead = nullptr;
        timeHead = currentTime; 
    }
}

bool linkedList::insert(const weatherdata& thisEntry)
{
    bool isDuplicate;
    entryNode* previousTime = nullptr;
    entryNode* currentTime = timeHead;
    //entryNode* currentTemperature = temperatureHead;
    //entryNode* previousTemperature = nullptr;
    //entryNode* currentWindspeed = windspeedHead;
    //entryNode* previousWindspeed = nullptr;
    //for above: do I need to set these to nullptr?
    //ALSO: do I NEED to assert head?
    while(currentTime != nullptr && currentTime->entry.getTimestamp() < thisEntry.getTimestamp())
    {
        //std::cout << "current" << currentTime->entry.getTimestamp() << '\n';
        //std::cout << "target" << thisEntry.getTimestamp();
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
    }

    
    //Just making the node, it's hangin' out
    //BUT ALSO TODO YOU NEED TO NOT SET A DIFFERENT ENTRY EACH TIME.
    //GIVE IT A MEMORY ADDRESS


    entryNode * newEntry = new entryNode;
    newEntry->entry = thisEntry;
    newEntry->nextTime = nullptr;
    //std::cout << thisEntry.getTimestamp();
    //DO leave these here(trust me)
    //newEntry->nextTemperature = nullptr;
    //newEntry->nextWindspeed = nullptr;

    //NEED TO DO THIS FOR EACH THREAD 
    newEntry->nextTime = currentTime;

    if(previousTime == nullptr)
    {
        timeHead = newEntry;
        temperatureHead = newEntry;
        windspeedHead = newEntry;
        //std::cout << newEntry->entry.getTimestamp();
        //std::cout << '\n';
    }
    else
    {
        previousTime->nextTime = newEntry;
        //std::cout << newEntry->entry.getTimestamp();
        //std::cout << '\n';
        //newEntry->nextTime = currentTime->nextTime;
        //currentTime->nextTime = newEntry;
        //std::cout << newEntry->entry;
        //NOT IN THIS PART! DO THESE SEPARATELY
        //previousTemperature->nextTemperature = newEntry;
        //previousWindspeed->nextWindspeed = newEntry;
    }
        
   // while(currentTemperature != nullptr && currentTemperature->entry.getTemperature() < thisEntry.getTemperature())
   // {
   //     previousTemperature = currentTemperature;
   //     currentTemperature = currentTemperature->nextTemperature;
   // }
   //     if(previousTemperature == nullptr)
   //     {
   //         temperatureHead = newEntry;
   //     }
   //     else
   //     {
   //         previousTemperature->nextTemperature = newEntry;
   //     }
   // while(currentWindspeed != nullptr && currentWindspeed->entry.getWindspeed() <= thisEntry.getWindspeed())
   // {
   //     previousWindspeed = currentWindspeed;
   //     currentWindspeed = currentWindspeed->nextWindspeed;
   // }
   //     if(previousWindspeed == nullptr)
   //     {
   //         windspeedHead = newEntry;
   //     }
   //     else
   //     {
   //         previousWindspeed->nextWindspeed = newEntry;
   //     }

    


    //std::cout << 
    listSize++;
    return isDuplicate;
}


void linkedList::printMe() const
{
    entryNode * current;
    for(current = timeHead; current; current = current->nextTime)
        std::cout << current->entry.getTimestamp() << '\n';
    std::cout << '\n' << '\n';
}


//TODO 5 same qustion about createReport. what would this look like?
//bool?
//hey wait. Should I just pass createReport(list, clean or dirty all the way up from createReport)?
//void linkedList::createReport() const
//{
//    entryNode* currentTime;
//    entryNode* currentTemperature;
//    entryNode* currentWindspeed;
//
//    for(currentTime = timeHead; currentTime; currentTime = currentTime->nextTime)
//    {
//                
//    }
//}




















//bool remove
//I THINK i CAN GET AWAY WITH JUST HAVING INSERT() REPLACE ALL OF THE VALUES IN AN EXISTING LIST
//BUT I WILL NEED TO DO A SCAN AFTERWARD AS A SUBROUTINE TO FIND PROPER PLACES FOR TEMPERATURE AND WINDSPEED. just like above except first you should link previous to oldnode->next 

//EDIT: seriously? for every goddamn pass I need to use the removeData function from weatherlog.cpp
//so I do need two write this. what the fuck bro.


























