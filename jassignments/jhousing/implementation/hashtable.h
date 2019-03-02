#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cmath>
#include <cstring>
#include "family.h"
using namespace std;
//x = multiplier for hash function
static int x = 32;
static int TABLEBIG = 7877;

//DUUDE CHANGE TABLEBIG BACK









struct familyPod
{
    family* nuclearFamily;
    familyPod* next;
};


class hashTable
{

    private:
        family** table;
        int tableSize;
        unsigned int hashNumber;
        family* Next;
        int numberizer = 0;
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
        size_t hashBrowns(const char* FID);
        const void dumpTable();
        void saysQuack();
        void navChain(family*& current);



};

#endif
