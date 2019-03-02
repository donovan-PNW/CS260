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
    database.addFamLEE(1, fimPinter);
    delete fimPinter;
    fimPinter = nullptr;

}

void familymgr::printAllFamilies()
{
    std::cout << "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy" << endl;

}
void familymgr::printSmallCircle(const char* FID)
{
    std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;

}









































