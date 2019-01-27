//OI!!! YOU NEED TO OVERLOAD ASSIGNMENT OPERATOR FOR POINTER CLASSES
//
//
//
#include "linkedlist.h"
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
    bool isSuccessful;
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
    newEntry->nextTemperature = currentTemperature;
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
    newEntry->nextWindspeed= currentWindspeed;
    if(previousWindspeed == nullptr)
    {
        windspeedHead = newEntry;
    }
    else
    {
        previousWindspeed->nextWindspeed = newEntry;
    }

    


    listSize++;
    return isSuccessful;
}

int linkedList::pullTime(int target)
{
    int index = 0;
    int timeStamp = 0;
    entryNode * current;
    current = timeHead;
    while(index <= target)
    {
       // std::cout << "hi\n";
        index++;
        current = current->nextTime;
        //current = current->nextTime;
        //current = current->nextTime;
    }
    timeStamp = current->entry.getTimestamp();
    //std::cout << timeStamp;
    return timeStamp;
    //THIS IS ALL WRONG YOU NEED TO DO IT ONE AT A TIME
}

int linkedList::totalizer() const
{
    int total = 0;
    entryNode * current;
    for(current = timeHead; current; current = current ->nextTime)
    {
        total++;
    }
    return total;
}



void linkedList::printMe() const
{
    entryNode * current = new entryNode;
    current = nullptr;
    for(current = timeHead; current; current = current->nextTime)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    current = nullptr;
    for(current = temperatureHead; current; current = current->nextTemperature)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    current = nullptr;
    for(current = windspeedHead; current; current = current->nextWindspeed)
    {
        cout << current->entry; 
    }
    std::cout << endl;
    delete current;
}


































