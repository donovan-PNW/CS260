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
    std::cout << "HIYEEE" << endl;
    FID = new char[strlen(newFID)+1];
    strcpy(FID, newFID);
    familyName = new char[strlen(newName)+1];
    strcpy(familyName, newName);
    memberCount = newMembers;
}

family::family(const family& otherFamily):
    FID(nullptr),
    familyName(nullptr),
    memberCount(0),
    familyFriend1(nullptr),
    familyFriend2(nullptr),
    familyFriend3(nullptr)
{
    std::cout << "KSDJF " << endl;
    setFID(otherFamily.FID);
    setFamilyName(otherFamily.familyName);
    setMemberCount(otherFamily.memberCount);
    //setF1(otherFamily.familyFriend1);
    //setF2(otherFamily.familyFriend2);
    //setF3(otherFamily.familyFriend3);
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
        setF1(otherFamily.familyFriend1);
        setF2(otherFamily.familyFriend2);
        setF3(otherFamily.familyFriend3);
        return *this;
    }
}


ostream& operator<<(ostream& out, const family& thisFamily)
{
    out << "Family ID: " << thisFamily.FID << endl;
    out << "  Name: " << thisFamily.familyName << endl;
    out << "  Members: " << thisFamily.memberCount << endl; 
    out << "  Friends: " ;
    if(thisFamily.familyFriend1)
    {
        out <<  thisFamily.familyFriend1;
    }
    if(thisFamily.familyFriend2)
        out <<  " " << thisFamily.familyFriend2;
    if(thisFamily.familyFriend3)
        out <<  " " << thisFamily.familyFriend3;

    out << endl;
    return out;
}


void family::setFID(const char* familyID)
{
    if(this->FID)
        delete[] this->FID;

    this->FID = new char[strlen(familyID)+1];
    strcpy(this->FID, familyID);
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

void family::setF1(const char* friend1)
{
    if(this->familyFriend1)
        delete[] this->familyFriend1;

    this->familyFriend1 = new char[strlen(friend1)+1];
    strcpy(this->familyFriend1, friend1);

}
void family::setF2(const char* friend2)
{
    if(this->familyFriend2)
        delete[] this->familyFriend2;

    this->familyFriend2 = new char[strlen(friend2)+1];
    strcpy(this->familyFriend2, friend2);

}
void family::setF3(const char* friend3)
{
    if(this->familyFriend3)
        delete[] this->familyFriend3;

    this->familyFriend3 = new char[strlen(friend3)+1];
    strcpy(this->familyFriend3, friend3);
}


bool family::addFriend(const char* friendFID)
{
    bool success = false;
    if(!this->familyFriend1)
    {
        this->familyFriend1 = new char[strlen(friendFID) + 1];
        strcpy(this->familyFriend1, friendFID);
        success = true;
    }
    else if(!familyFriend2)
    {
        familyFriend2 = new char[strlen(friendFID) + 1];
        strcpy(familyFriend2, friendFID);
        success = true;
    }
    else if(!familyFriend3)
    {
        familyFriend3 = new char[strlen(friendFID) + 1];
        strcpy(familyFriend3, friendFID);
        success = true;
    }
    

    return success;
}


const char* family::getFID()
{
    return(this->FID);
}



