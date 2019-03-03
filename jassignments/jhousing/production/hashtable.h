#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cmath>
#include <cstring>
#include "family.h"
using namespace std;

class hashTable
{

    private:
        family** table;
        int tableSize;
        unsigned int hashNumber;
        family* Next;
        int tally = 0;

    public:
        hashTable();
        hashTable(const int& tableSize);
        hashTable(hashTable& otherTable)=delete;
        hashTable operator=(hashTable&  otherTable)=delete;
        ~hashTable();

        void addFamily(family*& newFamily);
        const void findFamily(const char* FID);
        size_t hashBrowns(const char* FID);
        const void dumpTable();
        family* tablePrint();
        //void saysQuack();
        family* seek(const char* FID); 


};

#endif
