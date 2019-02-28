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

void hashTable::addFamily(const int& index, family*& newFamily)
{
    family* temporary = nullptr;
    std::cout << "infrom" << &newFamily << endl;
    temporary = new family(*newFamily);
    if(table[index])
    {
        temporary->setNextFamily(table[index]);
        std::cout << "ZIMZAMZOOZLE" << endl;
    }
    table[index] = temporary;



   // if(!table[index])
   // {
   //     table[index] = temporary;
   // }
   // else
   // {
   //     temporary->setNextFamily(table[index]);
   //     table[index] = temporary;
   // }
    //or: if tableindex, temp->setnext = tableindex
    //then: tablindex = temporary


    //family *tempFamily = new family(*newFamily);
    //std::cout << "outTo" << *tempFamily << endl;
    //
    //
    //if(table[index]){
    //    std::cout << "PPPPPPPP" << endl;
    //    temporary = new family(*table[index]);
    //}
    //table[index] = new family(*newFamily);
    //hashNumber = hashBrowns(table[index]->getFID());
    //if(temporary)
    //{
    //    std::cout << "PPPPPPPPPPPPPPPPPPPYYYYYYYYYYYYY" << endl;
    //    table[index]->setNextFamily(temporary);
    //}
    ////delete temporary;
    temporary = nullptr;
    std::cout << "HAHAHAHAHAHHASHNUMBER: " << hashNumber % 7877 << endl;
    std::cout << "outTo " << table[index] << endl;
    std::cout << "NEWFAMSTUFF" << *newFamily << endl;
    std::cout << "DOYOUFAMSTUFF" << *table[index] << endl;

}

//this works don't fuck with it
//except ok wait everything works but littlefield001 at what should be table 7366
//JK it works now! moved modulus to after for loop, as per instructions
size_t hashTable::hashBrowns(const char* FID)
{
    size_t hashBrown = 0;
    int length = strlen(FID);

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
        //const char* potato = table[index]->getFID();
        //hashNumber = hashBrowns(potato);
        std::cout << "ASCII A " << 'A' / 1 << endl;
        //std::cout << "YEE" << potato << endl;
        //testInt = 
        if(table[index] != nullptr)
        {
            //like this: printy(family)
            //{
            //    if(family->next != nullptr)
            //        printy(family)
            //    else
            //        cout << family
            //    call function that says print()
            //}
            std::cout << index << "ADDRESSS: "<< table[index] << " " << *table[index] << endl;

            if(table[index]->getNextFamily() != nullptr)
            {
                std::cout << "wut" << endl;
                //std::cout << "MAKE PRINT RECURSIVE TO GRAB FROM END OF LIST FIRST!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                //std::cout << "AS A SIDE NOTE: YOU NEED TO DELETE LINKED LISTS AS NORMAL, RIGHT NOW THIS JUST DELETES EACH ONE'S HEAD" << endl;

                std::cout << index << "NEXTINLINE " << *table[index]->getNextFamily() << endl;
            }
        }

    }
    std::cout << "outie quattro" << endl;
}


//void hashTable::navChain(family*& current)
//{
//    if(current->getNextFamily() != nullptr)
//    {
//        current = current->getNextFamily(); 
//    }
//}






























