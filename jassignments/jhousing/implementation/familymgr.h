#ifndef FAMILYMGR_H 
#define FAMILYMGR_H
#include<iostream>
#include<cstring>
#include "family.h"
#include "hashtable.h"
using namespace std;

class hashTable;
class familymgr
{
    private:
        family thisFamily;
        hashTable database;


    public:
        familymgr();
        ~familymgr();
        familymgr(familymgr& otherFamilyMgr)=delete;
        familymgr operator=(familymgr& otherFamilyMgr)=delete;
        void addFamily(family& famPtr);
        void printAllFamilies();
        void printSmallCircle(const char* FID);


};




#endif
