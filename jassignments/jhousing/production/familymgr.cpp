#include "familymgr.h"
#include "hashtable.h"

using namespace std;

familymgr::familymgr()
{
}

familymgr::~familymgr()
{
}


void familymgr::addFamily(family& famPtr)
{
    family *fimPinter = new family(famPtr);
    database.addFamily(fimPinter);
    delete fimPinter;
    fimPinter = nullptr;

}

void familymgr::printAllFamilies()
{

    for(int index = 0; index < 7877; index++)
    { std::cout << "table[" << index << "]:" << endl;
        std::cout << "List:" << endl;
        family* inFamily = database.tablePrint();
        while(inFamily != nullptr)
        {
            std::cout << *inFamily;
            inFamily = inFamily->getNextFamily();
        }
        std::cout << "--------------------" << endl;
        
    }
    
    //database.dumpTable();
}
void familymgr::printSmallCircle(const char* FID)
{
    std::cout << "Printing family and immediate friends " << FID << endl;
    std::cout << "== Family ==" << endl;
    family* famToPrint = nullptr;
    family* friendPrint1 = nullptr;
    family* friendPrint2 = nullptr;
    family* friendPrint3 = nullptr;
    char* friend1 = nullptr;
    char* friend2 = nullptr;
    char* friend3 = nullptr;
    famToPrint = database.seek(FID); 
    while(famToPrint != nullptr)
    {
        if(strcmp(FID, famToPrint->getFID()) == 0)
        {
            std::cout << *famToPrint;
            friend1 = famToPrint->getF1();
            friend2 = famToPrint->getF2();
            friend3 = famToPrint->getF3();
        }
        famToPrint = famToPrint->getNextFamily();
    }
    std::cout << endl << "== Friends (1 level) ==" << endl;
    friendPrint1 = database.seek(friend1);
    while(friendPrint1 != nullptr)
    {
        if(strcmp(friend1, friendPrint1->getFID()) == 0)
            std::cout << *friendPrint1;
        friendPrint1 = friendPrint1->getNextFamily();
    }
    friendPrint2 = database.seek(friend2);
    while(friendPrint2 != nullptr)
    {
        if(strcmp(friend2, friendPrint2->getFID()) == 0)
            std::cout << *friendPrint2;
        friendPrint2 = friendPrint2->getNextFamily();
    }
    friendPrint3 = database.seek(friend3);
    while(friendPrint3 != nullptr)
    {
        if(strcmp(friend3, friendPrint3->getFID()) == 0)
            std::cout << *friendPrint3;
        friendPrint3 = friendPrint3->getNextFamily();
    }
}


























































