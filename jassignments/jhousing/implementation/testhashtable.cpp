#include <iostream>
#include "hashtable.h"
#include "family.h"
#include <cstring>

using namespace std;

int main()
{
    const int HASHTABLESIZE = 50;
    const int NUMFAMILIES = 50;

    hashTable ht(HASHTABLESIZE);

    cout << "======================================================================" << endl;
    cout << "Testing inserts (should show full table)" << endl;

    //for (int i=0;i<NUMFAMILIES;i++)
    //for (int i=0;i<NUMFAMILIES;i++)
    //{
    //    char id[8];
    //    char name[8];
    //    char friendName[10];
    //    family* familyPtr;

    //    sprintf(id,"Test%d",i);
    //    sprintf(name,"Name%d",i);
    //    sprintf(friendName,"Friend%d",i);

    //    familyPtr = new family(id,name,1);
    //    familyPtr->addFriend(friendName);
    //    std::cout << "FriEND" << friendName << endl;
    //    //std::cout << i << " YO" << endl ;
    //    std::cout << "Infrom" << &familyPtr << endl;

    //    ht.addFamily(i, familyPtr);
    //    //ht.addFamily(id,*familyPtr);

    //    delete familyPtr;
    //    std::cout << i << " YO" << endl;
    //}

    //for(int i=0; i<5; i++)
    //{
        family* familyPtr;
        familyPtr = new family("Thornburg001", "dusty", 1);
        familyPtr->addFriend("Jerry");
        ht.addFamily(0, familyPtr);
        delete familyPtr;
        familyPtr = new family("Hoff001", "dusty", 1);
        familyPtr->addFriend("Jerry");
        ht.addFamily(1, familyPtr);
        delete familyPtr;
        familyPtr = new family("Littlefield001", "dusty", 1);
        familyPtr->addFriend("Jerry");
        ht.addFamily(2, familyPtr);
        delete familyPtr;
        familyPtr = new family("Dover002", "dusty", 1);
        familyPtr->addFriend("Jerry");
        ht.addFamily(3, familyPtr);
        delete familyPtr;
        familyPtr = new family("Taylor", "dusty", 1);
        familyPtr->addFriend("Jerry");
        ht.addFamily(4, familyPtr);
        delete familyPtr;

    //}

    ht.dumpTable();

    cout << "======================================================================" << endl;
    cout << "Testing searches (should show no errors)" << endl;
//    Hey you. You still need to do the lookup thing.
//        Also, you need to add a nextFamily pointer to the family class.

    //const family* foundFam;
    //foundFam = ht.lookup("Test44");
    //if (foundFam == nullptr)
	//cout << "ERROR searching for Test44" << endl;
    //foundFam = ht.lookup("Test39");
    //if (foundFam == nullptr)
	//cout << "ERROR searching for Test39" << endl;
    //foundFam = ht.lookup("Test999");
    //if (foundFam != nullptr)
	//cout << "ERROR searching for Test999" << endl;

    //cout << "======================================================================" << endl;
    //cout << "Testing removes (should show empty table)" << endl;

    //for (int i=0;i<NUMFAMILIES;i++)
    //{
	//char id[8];
	//sprintf(id,"Test%d",i);
	//ht.remove(id);
    //}
    //ht.dumpTable();

    return(0);
}
