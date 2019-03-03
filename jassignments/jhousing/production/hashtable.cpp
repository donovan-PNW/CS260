#include<iostream>
#include"hashtable.h"
#include<cstring>



hashTable::hashTable(): table(nullptr), tableSize(7877)
{
    table = new family* [tableSize];
    for(int index = 0; index < tableSize; index++)
    {
        table[index] = nullptr; //new family;
    }
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
                family* current = table[index];
                family* next = nullptr;
                while(current->getNextFamily() != nullptr)
                {
                    next = current->getNextFamily();
                    delete current;
                    current = next;
                }
                delete current;
                current = nullptr;
                table[index] = nullptr;
            }
        }
    }
    delete []table;
    table = nullptr;
}

void hashTable::addFamily(family*& newFamily)
{
    family* temporary = new family(*newFamily);
    int hashNumber = hashBrowns(newFamily->getFID());
    if(table[hashNumber])
    {
        family* upNext = nullptr;
        upNext = table[hashNumber];
        temporary->setNextFamily(upNext);
    }
    table[hashNumber] = temporary;
    temporary = nullptr;
}

size_t hashTable::hashBrowns(const char* FID)
{
    size_t hashBrown = 0; int length = strlen(FID);

    for(int index = 0; index < length; index++)
    {
        hashBrown = (32* hashBrown + FID[index]);
    }

    //hashBrown = x* (x* (x* (x* (x* (a) + b) + c) + d) + e);
    hashBrown = hashBrown % 7877;
    return hashBrown;

}

//void hashTable::saysQuack()
//{
//    std::cout << "quack quack quack " << endl;
//}

//NOTE: this function does not read along a linked list, but the final print function does.
//This one is therefore abandoned and is not called outside of the testing environment.
//const void hashTable::dumpTable()
//{
//    std::cout << "DUMPTABLE " << endl;
//    for(int index = 0; index < tableSize; index++)
//    {
//        std::cout << "ASCII A " << 'A' / 1 << endl;
//        if(table[index] != nullptr)
//        {
//            std::cout << index << "ADDRESSS: "<< table[index] << " " << *table[index] << endl;
//
//            if(table[index]->getNextFamily() != nullptr)
//            {
//                //std::cout << index << "NEXTINLINE " << *table[index]->getNextFamily() << endl;
//            }
//        }
//    }
//}


family* hashTable::tablePrint()
{
    family* podHead;
    //std::cout << "ASCII A " << 'A' / 1 << endl;
    podHead = table[tally];
    tally++;
    return podHead;
}

family* hashTable::seek(const char* FID)
{ int searchHash = hashTable::hashBrowns(FID);
    family* familyBack = nullptr;
    familyBack = table[searchHash];
    return familyBack;
}










