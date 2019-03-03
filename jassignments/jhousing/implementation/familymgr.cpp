#include "familymgr.h"
#include "hashtable.h"

using namespace std;

familymgr::familymgr()
{
}

familymgr::~familymgr()
{}


void familymgr::addFamily(family& famPtr)
{
    //std::cout << famPtr << endl;
    family *fimPinter = new family(famPtr);
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    std::cout << fimPinter << endl;
    database.addFamily(fimPinter);
    delete fimPinter;
    fimPinter = nullptr;

}

void familymgr::printAllFamilies()
{
    //bool truebool = true;

    //this bit is a little fucked, you need to just let it run until the infamily is over




    for(int index = 0; index < 7877; index++)
    {
        std::cout << "DICKS" << endl;
        family* inFamily = database.tablePrint();
        while(inFamily != nullptr)
        {
            std::cout << *inFamily << endl;
            inFamily = inFamily->getNextFamily();
            //family * tempointer = infamily->getnextfamily();
            //if(infamily != nullptr);
            //{

            //    std::cout << infamily;
            //    //infamily = 
            //    //tempointer = tempointer->getnextfamily();
            //    //if(tempointer->getnextfamily() != nullptr);
            //    //{
            //    //    //std::cout << temPointer->getNextFamily();
            //    //}
            //}
        }
        
    
    }
    
        //cout << inFamily;

    //database.dumpTable();
    std::cout << "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy" << endl;

}
void familymgr::printSmallCircle(const char* FID)
{
    family* famToPrint = nullptr;
    famToPrint = database.seek(FID); 
    char* fromFam = nullptr;
    while(famToPrint != nullptr)
    {

        std::cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;
        std::cout << "FID: " << FID << " getFID: " << famToPrint->getFID() << endl;
        if(strcmp(FID, famToPrint->getFID()) == 0)
        {
            std::cout << *famToPrint << endl;
        }
        famToPrint = famToPrint->getNextFamily();
    }
    std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;
}









































