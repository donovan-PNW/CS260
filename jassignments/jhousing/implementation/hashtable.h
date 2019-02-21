#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cmath>
#include "family.h"
using namespace std;

class hashTable
{

    private:
        family** table;
        int tableSize;
        family* Next;
        //hmmmm

    public:
        hashTable();
        hashTable(const int& tableSize);
        hashTable(hashTable& otherTable)=delete;
        hashTable operator=(hashTable&  otherTable)=delete;
        ~hashTable();

        //void addFamily(const char* FID, const family** newFamily);
        void addFamily(const int& index, family*& newFamily);
        const void findFamily(const char* FID);
        const void dumpTable();



};

#endif
