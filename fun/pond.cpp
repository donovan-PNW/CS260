#include "headers.h"
#include <iostream>

using namespace std;



pond::pond(const int& inRows, const int& inColumns) : 
    rows(inRows), columns(inColumns)
{
    int i;
    int j;
    thisPond = new char*[rows];
    for(i = 0; i < rows; i++)
    {
        thisPond[i] = new char[columns]; 
    }
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            thisPond[i][j] = ' ';
        }
    }
    thisPond[20][20] = 'R';
}

pond::~pond()
{
    for(int i = 0; i < rows; i++)
    {
        delete [] thisPond[i]; 
        thisPond[i]=nullptr;
    }
    delete [] thisPond;
    thisPond = nullptr;
}


const void pond::ripple() //prints to cout
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << thisPond[i][j];
        }
    }
}

void pond::wave()
{
    subWave(drop0);
    subWave(drop1);
    subWave(drop2);
    subWave(drop3);
    subWave(drop4);
    subWave(drop5);
    subWave(drop6);
    subWave(drop7);
    subWave(drop8);
    subWave(drop9);
    subWave(drop10);

}

void pond::subWave(droplet& inDrop)
{
    if(!inDrop.isActive()) 
    {
        inDrop = droplet(rand() % rows, rand() % columns);
    }
    else
    {
        char character;
        int x;
        int y;
        aDot temp;
        temp = inDrop.move();
        x = temp.x;
        y = temp.y;
 //       isjadf //TODO REWORK RING FUNCTION SO THAT YOU CAN PASS INDIVIDUAL NUMBERS THROUGH
        character = temp.character;
        std::cout << character;
        std::cout << x << " " << y; 
        thisPond[x][y] = character;
        temp = inDrop.ring("light");
        //while(!temp.ringComplete)
        //{
        x = temp.x;
        y = temp.y;
        character = temp.character;
        if(x < rows)
        {
            if(y < columns)
            {
                thisPond[x][y] = character;
            }
        }
        //if(pondClock%4 != 0)
        {
        temp = inDrop.ring("dark");
        //while(!temp.ringComplete)
        //{
        x = temp.x;
        y = temp.y;
        character = temp.character;
        if(x < rows)
        {
            if(y < columns)
            {
                thisPond[x][y] = character;
            }
        }
        }
        //else
        {
            temp = inDrop.ring("nextCrest");
            //while(!temp.ringComplete)
            //{
            x = temp.x;
            y = temp.y;
            character = temp.character;
            if(x < rows)
            {
                if(y < columns)
                {
                    thisPond[x][y] = character;
                }
            }
        }
        temp = inDrop.ring("darkCrest");
        //while(!temp.ringComplete)
        //{
        x = temp.x;
        y = temp.y;
        character = temp.character;
        if(x < rows)
        {
            if(y < columns)
            {
                thisPond[x][y] = character;
            }
        }

//        pondClock++;
        //temp = inDrop.ringDark();
        //{

        //
        //} 
        //}
        //while(inDrop.move())
        //{
        //     
        //}
    }
}




void pond::setPlace(const int& inRow, const int& inCol, const char& inChar)
{
    thisPond[inRow][inCol] = inChar; 
}







droplet::droplet()
{
    
}





droplet::droplet(const int& inRow, const int& inCol):
    row(inRow), col(inCol) 
{
    delay = rand() % 7 + 1;
    magnitude = rand() % 25 + 4;
    active = true;
}

droplet::~droplet()
{
}

bool droplet::isActive()
{
    return active;
}

aDot droplet::move()
{
    if(delay > 0)
    {
        front.x = row;
        front.y = col;
        front.character = ' ';
        delay--;
    }
    else if(magnitude > maturity)
    {
        if(switcher%3 == 0)
        {
            front.x = row;
            front.y = col;
            front.character = '*';
            switcher++;
        }
        else
        {
            front.x = row;
            front.y = col;
            front.character = ' ';
            switcher++;
            
        }
    }
    else
    {
        front.x = row;
        front.y = col;
        front.character = ' ';
        active = false;
    }
    cout << maturity;
    maturity++;

    return front;
}

//TODO GOOD! now make it a modulus val. if edge%maturity == 1 do *, else if == 2 do " " else (mod 3 4 or 5) just return.
aDot droplet::ring(char* lightDark)
{
    front.x = row;
    front.y = col;
    //THIS NEEDS TO BE 0 until delay is over. Figure it out.
    int radius = maturity;
    //if(delay != 0)
    //    return front;
    //if(ringSwitcher % 3  == 0)
    //{
    if(strcmp(lightDark, "light") == 0)
    {
        front.character = '*';
        front.y = col + radius; //;front.y - 1 + radius; // 1;
    }
    else if((strcmp(lightDark, "dark") == 0))// && (switcher % 3 != 2))
    {
        front.character = ' ';
        front.y = col + radius - 1; //;front.y - 1 + radius; // 1;
    }
    else if(strcmp(lightDark, "nextCrest") == 0)
    {
        front.character = '*';
        front.y = col + radius - 5; //;front.y - 1 + radius; // 1;
    }
    front.ringComplete = true;
    ringSwitcher++;
    edge++;
    return front;
}


























