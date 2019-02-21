#include<iostream>
#include"hashtable.h"

hashTable::hashTable(): table(nullptr), tableSize(0)
{
}


hashTable::hashTable(const int& tableSize): table(nullptr), tableSize(tableSize)
{
    
    table = new family* [tableSize];
    for(int index = 0; index < tableSize; index++)
    {
        table[index] = nullptr; //new family;
    }
}

hashTable::~hashTable()
{
    for(int index = 0; index < tableSize; index++)
    {
        for(int index = 0; index < tableSize; index++)
        {
            if(table[index])
            {
                delete table[index];
                std::cout <<"DESTROYDEX " << index << endl;
                table[index] = nullptr;
            }
        }
    }
    delete []table;
    table = nullptr;
}

void hashTable::addFamily(const int& index, family*& newFamily)
{
    std::cout << "infrom" << &newFamily << endl;
    //family *tempFamily = new family(*newFamily);
    //std::cout << "outTo" << *tempFamily << endl;
    table[index] = new family(*newFamily);
    std::cout << "outTo " << table[index] << endl;
    //std::cout << "NEWFAMSTUFF" << *newFamily << endl;

}

const void hashTable::dumpTable()
{
    std::cout << "DUMPTABLE " << endl;
    for(int index = 0; index < tableSize; index++)
    {
        std::cout << index << " : "<< *table[index] << endl;;
    
    }
}








