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
    {
        family* inFamily = database.tablePrint();
        while(inFamily != nullptr)
        {
            std::cout << *inFamily << endl;
            inFamily = inFamily->getNextFamily();
        }
        
    
    }
    
    //database.dumpTable();
}
void familymgr::printSmallCircle(const char* FID)
{
    family* famToPrint = nullptr;
    famToPrint = database.seek(FID); 
    while(famToPrint != nullptr)
    {

        if(strcmp(FID, famToPrint->getFID()) == 0)
        {
            std::cout << *famToPrint << endl;
        }
        famToPrint = famToPrint->getNextFamily();
    }
}









































