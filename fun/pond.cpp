#include "headers.h"

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
    if(!drop0.isActive()) 
    {
        drop0 = droplet(rows, columns);
    }
    else
    {
        drop0.move();
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
    delay = rand() % 20000;
    magnitude = rand() % 16 + 4;
    active = true;
}


droplet::~droplet()
{

}


bool droplet::isActive()
{
    return active;
}

void droplet::move(int& inRow, int& inCol, pond*& thisHerePond)
{
    maturity++;
    if(maturity >= magnitude)
    {
        active = false;
    }
    pond::setPlace(inRow, inCol, '*')
}
























