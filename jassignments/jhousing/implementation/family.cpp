#include <iostream>
#include <cstring>
#include "family.h"

using namespace std;

family::family()
{
    FID = nullptr;
    familyName = nullptr;
    memberCount = 0;
    familyFriend1 = nullptr;
    familyFriend2 = nullptr;
    familyFriend3 = nullptr;

//strcpy(FID, "");
    //strcpy(familyName, "");
    //memberCount = 0;
    //strcpy(familyFriend1, "");
    //strcpy(familyFriend2, "");
    //strcpy(familyFriend3, "");
}

family::family(const char* newFID, const char* newName, const int& newMembers):
    FID(nullptr),
    familyName(nullptr),
    memberCount(0),
    familyFriend1(nullptr),
    familyFriend2(nullptr),
    familyFriend3(nullptr)
{
    std::cout << newFID << endl;
    std::cout << "SOUP7" << endl;
    setFID(newFID);
    setFamilyName(newName);
    setMemberCount(newMembers);
}

family::family(const family& otherFamily)
{
    FID = otherFamily.FID;
    familyName = otherFamily.familyName;
    memberCount = otherFamily.memberCount;
    familyFriend1 = otherFamily.familyFriend1;
    familyFriend2 = otherFamily.familyFriend2;
    familyFriend3 = otherFamily.familyFriend3;
}

family::~family()
{
    std::cout << "BYEEE" << endl;
    if(FID)
        delete[] FID;
    if(familyName)
        delete[] familyName;
    if(familyFriend1)
        delete[] familyFriend1;
    if(familyFriend2)
        delete[] familyFriend2;
    if(familyFriend3)
        delete[] familyFriend3;
}

const family& family::operator=(const family& otherFamily)
{
    //FIX THE DOUBLE RETURNS!!!
    if(this == &otherFamily)
        return *this;
    else
    {
        setFID(otherFamily.FID);
        setFamilyName(otherFamily.familyName);
        setMemberCount(otherFamily.memberCount);
        //setF1(otherFamily.familyFriend1);
        //strcpy(this->FID, otherFamily.FID);
        //strcpy(this->familyName, otherFamily.familyName);
        //this->memberCount = otherFamily.memberCount;
        //strcpy(this->familyFriends, otherFamily.familyFriends);
        return *this;
    }
}


ostream& operator<<(std::ostream& out, const family& thisFamily)
{
    out << "here's yer family dumbass" << endl;
    out << thisFamily.FID << endl << thisFamily.familyName << endl;
    out << thisFamily.memberCount << endl; //<< thisFamily.familyFriend1 << " " << thisFamily.familyFriend2 << " " << thisFamily.familyFriend3 << endl;

    std::cout << "RAR" << endl;
    return out;
}


void family::setFID(const char* familyID)
{
    std::cout << "SOUP*" << endl;
    if(this->FID)
        delete[] this->FID;


    std::cout << "SOUP9" << endl;
    this->FID = new char[strlen(familyID)+1];
    strcpy(this->FID, familyID);
    std::cout << "SOUP1" << endl;
}

void family::setFamilyName(const char* newFamilyName)
{
    if(this->familyName)
        delete[] this->familyName;


    this->familyName = new char[strlen(newFamilyName)+1];
    strcpy(this->familyName, newFamilyName);
}

void family::setMemberCount(const int& howMany)
{
    this->memberCount = howMany; 
}



bool family::addFriend(const char* friendFID)
{
    bool success = true;
    if(strlen(this->familyFriend1) == 0)
        strcpy(this->familyFriend1, friendFID);
    else if(strlen(this->familyFriend2) == 0)
        strcpy(this->familyFriend2, friendFID);
    else if(strlen(this->familyFriend3) == 0)
        strcpy(this->familyFriend3, friendFID);
    else
        success = false;

    return success;
}


const char* family::getFID()
{
    return(this->FID);
}

































