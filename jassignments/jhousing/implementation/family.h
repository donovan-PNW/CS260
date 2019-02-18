#ifndef FAMILY_H
#define FAMILY_H
#include<iostream>
using namespace std;

class family
{

    private:
        char *FID;//[20];
        char *familyName;//[20];
        int memberCount;
        char *familyFriends;

    public:
        family();
        family(const char* FID, const char* name, const int& members);
        //NOOOO YOU HAVE TO DO THESE I THINK
        family(const family& otherFamily)=delete;
        family operator=(family& otherFamily)=delete;
        ~family();

        char* getFID();
        char* getFamilyName();
        int getMemberCount();
        char* getFamilyFriends();


        void addFriend(const char* friendFID);
        void setFID(const char* familyID);
        void setFamilyName(const char* familyName);
        void setMemberCount(const int& howMany);
        
};

#endif
