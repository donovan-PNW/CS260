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
        //WHILE X != 9999, TEMP = INDROP.MOVE(),
        //INSIDE INDROP, CHANGE A VARIABLE EACH TIME MOVE IS CALLED
        character = temp.character;
        std::cout << character;
        std::cout << x << " " << y; 
        thisPond[x][y] = character;
        temp = inDrop.ring();
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



    //if(!drop0.isActive()) 
    //{
    //    drop0 = droplet(rand() % rows, rand() % columns);
    //}
    //else
    //{
    //    char character;
    //    int x;
    //    int y;
    //    aDot temp;
    //    temp = drop0.move();
    //    x = temp.x;
    //    y = temp.y;
    //    character = temp.character;
    //    std::cout << character;
    //    std::cout << x << " " << y; 
    //    thisPond[x][y] = character;
    //    //while(drop0.move())
    //    //{
    //    //     
    //    //}
    //}
    //if(!drop1.isActive()) 
    //{
    //    drop1 = droplet(rand() % rows, rand() % columns);
    //}
    //else
    //{
    //    char character;
    //    int x;
    //    int y;
    //    aDot temp;
    //    temp = drop1.move();
    //    x = temp.x;
    //    y = temp.y;
    //    character = temp.character;
    //    std::cout << character;
    //    std::cout << x << " " << y; 
    //    thisPond[x][y] = character;
    //    //while(drop0.move())
    //    //{
    //    //     
    //    //}
    //}
    

//}

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
    delay = rand() % 5 + 1;
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

aDot droplet::ring()
{
    front.x = row;
    front.y = col;
    int radius = maturity;
    if(ringSwitcher % 3  == 0)
    {
        front.character = '*';
    }
    else
    {
        std::cout << "else";
        front.character = ' ';
    }

    //for(int i = 0; i <= radius; i++)
    
    front.x = front.x;
    front.y = col + radius - 1; //;front.y - 1 + radius; // 1;
    ringSwitcher++;
    
    //front.character = '*';
   
    
    //    std::cout << "MATURITY: " << maturity << "     ";
        front.ringComplete = true;
    //}
    //else
    //{
    //    front.x = (row + 1);
    //    front.y = col; 
    //}
    edge++;
    return front;
}



//bool droplet::move(int& inRow, int& inCol, pond**& thisHerePond)
//{
//    thisHerePond.setPlace(inRow, inCol, '*')
//    //thisHerePond[inRow][inCol] = '*';
//    if(maturity >= magnitude)
//    {
//        active = false;
//    }
//    maturity++;
//}
























