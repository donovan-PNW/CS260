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
    std::cout << "ALAKJA AO A " << *table[index] << endl;
    hashNumber = hashBrowns(table[index]->getFID());
    std::cout << "HASHNUMBER: " << hashNumber << endl;
    std::cout << "outTo " << table[index] << endl;
    //std::cout << "NEWFAMSTUFF" << *newFamily << endl;

}

unsigned int hashTable::hashBrowns(const char* FID)
{
    unsigned int hashBrown = 0;

    std::cout << FID[0];  
    std::cout << FID[1];  
    std::cout << FID[2];  
    std::cout << "YO BROSEF" << endl;
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
        //const char* potato = table[index]->getFID();
        //hashNumber = hashBrowns(potato);
        std::cout << "ASCII A " << 'A' / 1 << endl;
        //std::cout << "YEE" << potato << endl;
        //testInt = 
        std::cout << index << " : "<< table[index] << " " << *table[index] << endl;;

    }
    std::cout << "outie quattro" << endl;
}








