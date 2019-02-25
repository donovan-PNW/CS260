#ifndef HEADERS_H
#define HEADERS_H 
#include <iostream>
//#include <cstdlib> //not necessary probably but why not
#include <ctime>
#include <chrono>
#include <random>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>

using namespace std;

//int randumb(int size)
//{
//    int temp;
//    temp = rand()% size;
//    return temp;
//
//}
//

struct aDot
{
    int x;
    int y;
    char character;
    bool ringComplete = false;
};

class pond;

class droplet
{
    private:
        aDot front;
        int edge = 1;
        int row = 0;
        int col = 0;
        int delay = 0;
        int magnitude = 0; //do this one internally instead of passing it in;
        int maturity = 0;
        char* pointsTo = nullptr;
        bool active = false;
        bool circumNav= false;
        size_t switcher = 0;
        int ringSwitcher = 0;

    public:
        droplet();
        droplet(const int& inRow, const int& inCol);
        droplet(const droplet& someDroplet)=delete;
        ~droplet();
        //void move(pond*& thisHerePond);
        bool isActive();
        aDot move();
        aDot ring(char* lightDark);
};

class pond
{
    private:
        const int rows;
        const int columns;
        char** thisPond;
        droplet drop0;
        droplet drop1;
        droplet drop2;
        droplet drop3;
        droplet drop4;
        droplet drop5;
        droplet drop6;
        droplet drop7;
        droplet drop8;
        droplet drop9;
        droplet drop10;
    public:
        pond()=delete;
        pond(const int& inRows, const int& columns);
        pond(const pond& somepond)=delete;
        //pond operator=(const pond& somePond);
        ~pond();
        const void ripple();
        void wave();
        //friend void droplet::move(pond*& thisHerePond);
        //https://stackoverflow.com/questions/10546391/specify-a-class-member-function-as-a-friend-of-another-class
        void setPlace(const int& inRow, const int& inCol, const char& inChar);
        void subWave(droplet& inDrop);
};

class fish
{

};

//class bugs
//class rain

    //void create(int inRow, int inCol, int inMagnitude, int inMaturity, char*& pointsTo)
    //{
    //    row = inRow;
    //    col = inCol;
    //    magnitude = rand() % 1001;
    //    maturity = inMaturity;
    //}

    //void move()
    //{
    //    while(magnitude > 0)
    //    {
    //        {
    //        } //        magnitude--;
    //    }
    //}
//};



#endif
