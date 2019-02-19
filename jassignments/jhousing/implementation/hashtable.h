#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "family.h"
using namespace std;

class hashTable
{

    private:
        family* tableHead;
        int tableSize;
        //hmmmm

    public:
        hashTable();
        hashTable(hashTable& otherTable)=delete;
        hashTable operator=(hashTable&  otherTable)=delete;
        ~hashTable();

        void addFamily(const char* FID, const family*& newFamily);
        void findFamily(const char* FID);
        void dumpTable();



};

#endif
