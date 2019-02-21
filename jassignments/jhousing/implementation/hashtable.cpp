#include<iostream>
#include"hashtable.h"
#include<cstring>

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
    hashNumber = hashBrowns(table[index]->getFID());
    std::cout << "HAHAHAHAHAHHASHNUMBER: " << hashNumber % 7877 << endl;
    std::cout << "outTo " << table[index] << endl;
    //std::cout << "NEWFAMSTUFF" << *newFamily << endl;

}

size_t hashTable::hashBrowns(const char* FID)
{
    size_t hashBrown = 0;


    int length =strlen(FID);
    hashBrown = FID[0];
    std::cout << "THISLETTER" << FID[0] << endl;
    std::cout << "THISLETTER" << FID[0]/1 << endl;
    std::cout << "HASHMOD " << hashBrown % 7877 << endl;
    //for(int index = 0; index < length-1; index++)
    //{
       // hashBrown = (hashBrown + FID[0]) * 32;
    //}
    for(int index = 1; index < length; index++)
    {
        hashBrown = (hashBrown + hashBrown*pow(32,index));
        hashBrown = hashBrown % 7877;
        std::cout << "THISLETTER" << FID[index] << endl;
        std::cout << "THISPOWER" << pow(32,index) << endl;
        std::cout << "GIANT" << hashBrown << endl;
        std::cout << "HASHMOD " << hashBrown % 7877 << endl;
    }





    //unsigned int a = 0;
    //unsigned int b = 0;
    //unsigned int c = 0;
    //unsigned int d = 0;
    //unsigned int e = 0;

    //a = strlen(FID);
    //b = FID[0];
    //c = FID[1];
    //d = FID[2];
    //e = FID[3];
    //std::cout << a << endl;  
    //std::cout << b << endl;  
    //std::cout << c << endl;  
    //hashBrown = x* (x* (x* (x* (x* (a) + b) + c) + d) + e);
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
        //const char* potato = table[index]->getFID();
        //hashNumber = hashBrowns(potato);
        std::cout << "ASCII A " << 'A' / 1 << endl;
        //std::cout << "YEE" << potato << endl;
        //testInt = 
        if(table[index])
        {
        std::cout << index << " : "<< table[index] << " " << *table[index] << endl;
        }

    }
    std::cout << "outie quattro" << endl;
}








