#include<iostream>
#include"hashtable.h"
#include<cstring>



hashTable::hashTable(): table(nullptr), tableSize(TABLEBIG)
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
                //delete table[index];
                std::cout <<"DESTROYDEX " << index << endl;
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
        //std::cout << "ZIMZAMZOOZLE" << endl;
    }
    table[hashNumber] = temporary;
    temporary = nullptr;
    //numberizer++;
    //numberizer = numberizer % 7877;
    
    //std::cout << "outTo " << table[index] << endl;
    //std::cout << "NEWFAMSTUFF" << *newFamily << endl;
    //std::cout << "DOYOUFAMSTUFF" << *table[index] << endl;

}

//this works don't fuck with it
//except ok wait everything works but littlefield001 at what should be table 7366
//JK it works now! moved modulus to after for loop, as per instructions
size_t hashTable::hashBrowns(const char* FID)
{
    size_t hashBrown = 0; int length = strlen(FID);

    for(int index = 0; index < length; index++)
    {
        hashBrown = (32* hashBrown + FID[index]);// % 7877;
    }

    //hashBrown = x* (x* (x* (x* (x* (a) + b) + c) + d) + e);
    hashBrown = hashBrown % 7877;
    std:: cout << "HASHBROWN " << hashBrown << endl;
    //std::cout << "YO BROSEF" << endl;
    return hashBrown;

}

//void hashTable::saysQuack()
//{
//    std::cout << "quack quack quack " << endl;
//}

const void hashTable::dumpTable()
{
    std::cout << "DUMPTABLE " << endl;
    for(int index = 0; index < tableSize; index++)
    {
        std::cout << "ASCII A " << 'A' / 1 << endl;
        if(table[index] != nullptr)
        {
            std::cout << index << "ADDRESSS: "<< table[index] << " " << *table[index] << endl;

            if(table[index]->getNextFamily() != nullptr)
            {
                //std::cout << index << "NEXTINLINE " << *table[index]->getNextFamily() << endl;
            }
        }

    }
    std::cout << "outie quattro" << endl;
}


family* hashTable::tablePrint()
{

family* podHead;

    
    std::cout << "ASCII A " << 'A' / 1 << endl;
    //if(table[tally] != nullptr)
    //{
    podHead = table[tally];
        //std::cout << tally << "ADDRESSS: " << table[tally] << " " << *table[tally] << endl;

        //if(table[tally]->getNextFamily() != nullptr)
        //{
        //    endOfChain = false;
        //    std::cout << "wut" << endl;
        //    std::cout << tally << "NEXTINLINE " << *table[tally]->getNextFamily() << endl;
        //}
        //else
        //{
        //    endOfChain = true;
        //    tally++;
        //}

    //}
    tally++;
    return podHead;
}

family* hashTable::seek(const char* FID)
{
    std::cout << FID << endl;
    int searchHash = hashTable::hashBrowns(FID);
    family* familyBack = nullptr;
    family* inFamily = nullptr;

    familyBack = table[searchHash];
    std::cout << "searchHash " << searchHash << "FID: " << familyBack->getFID() << endl;
    for(table

    //for(int i = 0; i < 7877; i++)
    //{
    //    //std::cout << "YEOW"<< i << endl;
    //    inFamily = table[i];
    //    while(inFamily != nullptr)
    //    {
    //        std::cout << inFamily->getFID() << endl;
    //        if(FID == inFamily->getFID())
    //        {
    //            familyBack = inFamily; 
    //            std::cout << "rrrrrrrrrrr" << endl;
    //            std::cout << *familyBack << endl;
    //        }
    //        inFamily = inFamily->getNextFamily();
    //    }
    //}

    return familyBack;
}

//void hashTable::navChain(family*& current)
//{
//    if(current->getNextFamily() != nullptr)
//    {
//        current = current->getNextFamily(); 
//    }
//}






























