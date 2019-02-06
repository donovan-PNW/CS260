#ifndef RESULTDATA_H
#define RESULTDATA_H 

#include <iostream>
#include <cstring>
#include <cassert>


using namespace std;

class resultdata
{
    private:
        int roverID;
        int xCoordinate;
        int yCoordinate;
        int results;

    public:

        resultdata();
        //maybe fix this later if I feel like it?
        resultdata(const resultdata& otherResultdata)=delete;
        resultdata(int newRoverID, int newXCoordinate, int newYCoordinate, int newResults);
        ~resultdata();
        void print() const; 
};





#endif
