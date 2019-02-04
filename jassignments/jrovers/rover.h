#ifndef ROVER_H
#define ROVER_H

#include <iostream>
//#include "queue.h"

using namespace std;


class rover
{
    private:
        int ID;
        int xCoordinate;
        int yCoordinate;
        int * resultsPointer;
        //how do I even IDK



    public:

        void deploy();
        //print "Rover (<ID>) deploying..."
        //print "Rover (<ID>) ready"
        void move(int x, int y);
        //changes xy coords and stores new location on the stack.
        //prints message saying "Rover (<ID>) moving to location <x>, <y>."
        void corescan();
        //prints a message "Rover(<ID>) scanning."
        //calls scandata class  with rover's current xy position
        //and stores results in results queue
        void dock();
        //prints "Rover (<ID>) returning to base."
        //Uses the entries from the stack to issue a sequence of moves to backtrack
        //back to base. Needs to print out each move as it goes past them.
        //Once back to base, print "Rover (<ID>) at base and docked". 
        //Need to reset the x y coords to 0 when docked

};




#endif
