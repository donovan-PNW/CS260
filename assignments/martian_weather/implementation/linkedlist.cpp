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
    entryNode* previousTemperature = nullptr;
    entryNode* currentTemperature = temperatureHead;
    entryNode* previousWindspeed = nullptr;
    entryNode* currentWindspeed = windspeedHead;
    
    //Just making the node, it's hangin' out
    entryNode * newEntry = new entryNode;
    newEntry->entry = thisEntry;
    newEntry->nextTime = nullptr;
    newEntry->nextTemperature = nullptr;
    newEntry->nextWindspeed = nullptr;
    //ALSO: do I NEED to assert head?
    while(currentTime != nullptr && currentTime->entry.getTimestamp() < thisEntry.getTimestamp())
    {
        previousTime = currentTime;
        currentTime = currentTime->nextTime;
    }

    

    //AAAAHHHH FUCK! TODO YOU NEED TO CHECK IF ALL OF THE VALUES ARE THE SAME BEFORE INSERTING. LIKE, IF NEWENTRY.TIME = CURRENT TIME && IF NEWENTRY.TEMP = CURRENT TEMP ETC. CHECK ALL 3. OR SCREW IT. YOU CAN JUST DO THIS IN A SINGLE IF THINGY (LIKE THE WHILE LOOP ABOVE)
    //NEED TO DO THIS FOR EACH THREAD 
    newEntry->nextTime = currentTime;

    if(previousTime == nullptr)
    {
        timeHead = newEntry;
    }
    else
    {
        previousTime->nextTime = newEntry;
    }
    //std::cout << newEntry->entry.getTemperature() << '\n';
        
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

    while(currentWindspeed != nullptr && currentWindspeed->entry.getWindspeed() < thisEntry.getWindspeed())

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

    


    listSize++;
    return isDuplicate;
}


void linkedList::printMe() const
{
    entryNode * current;
    for(current = timeHead; current; current = current->nextTime)
        {
            //std::cout << current->entry.getTimestamp() << '\n';
            cout << current->entry; 

        }
   // 
   // for(current = temperatureHead; current; current = current->nextTemperature)
   //     std::cout << current->entry.getTemperature() << '\n';

   // for(current = windspeedHead; current; current = current->nextWindspeed)
   //     std::cout << current->entry.getWindspeed() << '\n';
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


























