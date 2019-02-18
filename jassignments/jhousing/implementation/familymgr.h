#ifndef FAMILYMGR_H 
#define FAMILYMGR_H
#include<iostream>
#include "family.h"
#include "hashtable.h"
using namespace std;

class familymgr
{
    private:
        family thisFamily;
        hashTable database;


    public:
        familymgr();
        familymgr(familymgr& otherFamilyMgr)=delete;
        familymgr operator=(familymgr& otherFamilyMgr)=delete;
        family addFamily(const family* famPtr);
        void printAllFamilies();
        void printSmallCircle(const char* FID);


};




#endif
