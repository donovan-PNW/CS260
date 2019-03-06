#include <iostream>
#include "family.h"

using namespace std;

void addFriendHelper(family& fam,const char* myfriend)
{
    
    bool isTrue = fam.addFriend(myfriend);
    cout << "TRUE?" << isTrue << endl;
    if (!isTrue)
    //{
        cout << "Too many friends for me \n";//<< fam.getFID() << endl;
    //}
}

int main()
{
    // Test some of the basic family functionality. Normally a test like this
    // should be self-checking but for this class I am just having it print to
    // screen since I think that will be more helpful for you (the students)

    family fam("Test001","Test",3);
    cout << fam;

    addFriendHelper(fam,"Friend001");
    cout << fam;


    addFriendHelper(fam,"Fri002");
    cout << fam;

    addFriendHelper(fam,"end003");
    cout << fam;

    addFriendHelper(fam,"Friend004");
    cout << fam;

    return(0);
}
