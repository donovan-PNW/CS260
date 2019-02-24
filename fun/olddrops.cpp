#include <iostream>
#include <cstdlib> //not necessary probably but why not
#include <ctime>
#include <chrono>
#include <random>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;


//struct pond
//{
//    char *lake;
//    int row = 0;
//    int col = 0;
//    for(int i = 0; i < row; i++)
//    {
//        for(int j = 0; j < w.ws_col; j++)
//        {
//            pond[i][j] = " ";
//        }
//    }
//    pond[w.ws_row][w.ws_col] = "A";
//
//
//};

struct droplet
{
    int row = 0;
    int col = 0;
    int magnitude = 0;
    int maturity = 0;
    char* pointsTo = nullptr;

    void create(int inRow, int inCol, int inMagnitude, int inMaturity, char*& pointsTo)
    {
        row = inRow;
        col = inCol;
        magnitude = rand() % 1001;
        maturity = inMaturity;
    }

    void move()
    {
        while(magnitude > 0)
        {
            {
                pond[row][col] = "*";
            }
            magnitude--;
        }
        pond[row][col] = " ";
    }
};

int main()
{
    srand(time(nullptr));
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
    int slotTotal = w.ws_row * w.ws_col;
    //cout << "slotTotal" << slotTotal << endl;

    //char letter = 'A';
    //for(int i = 0; i < w.ws_row; i++)
    //{
    //    for(int j=0; j < w.ws_col; j++)
    //    {
    //        cout << static_cast<char>(letter + (i-1));
    //    }
    //}
    
    usleep(640000);
    char* pond[w.ws_row][w.ws_col];
    for(int i = 0; i < (w.ws_row); i++)
    {
        for(int j = 0; j < w.ws_col; j++)
        {
            pond[i][j] = " ";
        //    cout << pond[i][j];
        }
    }

    //cout << endl << endl << endl << endl;
    //for(int i = 0; i < 24; i++)
    //{
    //    for(int j=0; j < 80; j++)
    //    {
    //        cout << static_cast<char>(letter + (i-1));
    //    }
    //}

    system("setterm -cursor off");


    droplet drop0;
    droplet drop1;
    droplet drop2;
    droplet drop3;
    droplet drop4;
    droplet drop5;
    droplet drop6;
    droplet drop7;
    size_t timeMaster = 0;
    



    
    //int mag7 = 0; //rand()% slotTotal;
    while(true)//timeMaster < 10)
    {

        
        if(drop0.magnitude == 0)
        {
            drop0.create(rand()%w.ws_row, rand()%w.ws_col,rand()%17, 0, **pond);
            //center0 = rand() % slotTotal;
            //mag0 = rand() % 15 + 3;
            //cout << "+"; 
        }
        else if(drop0.magnitude != 0)
        {
            drop0.move();
            //pond[drop0.center] = "*";
        }
        //if(mag1 == 0)
        //{
        //    center1 = rand() % slotTotal;
        //    mag1 = rand() % 15 + 3;
        //    //cout << "*"; 
        //}
        //if(mag2 == 0)
        //{
        //    center2 = rand() % slotTotal;
        //    mag2 = rand() % 15 + 3;
        //    //cout << "@"; 
        //}
        //if(mag3 == 0)
        //{
        //    center3 = rand() % slotTotal;
        //    mag3 = rand() % 15 + 3;
        //    //cout << "$";
        //}
        //if(mag4 == 0)
        //{
        //    center4 = rand() % slotTotal;
        //    mag4 = rand() % 15 + 3;
        //    //cout << "#";
        //}
        //if(mag5 == 0)
        //{
        //    center5 = rand() % slotTotal;
        //    mag5 = rand() % 15 + 3;
        //    //cout << "~";
        //}
        //if(mag6 == 0)
        //{
        //    center6 = rand() % slotTotal;
        //    mag6 = rand() % 15 + 3;
        //    //cout << "~";
        //}
        //if(mag7 == 0)
        //{
        //    center7 = rand() % slotTotal;
        //    mag7 = rand() % 15 + 3;
        //    //cout << "~";
        //}
        //else
        //{
        //    //mag0 = rand() % 15 + 3;
        //    //cout << " ";
        //}



        //droplet(center0, magnitude0, maturity0);
        //droplet(center1, magnitude1, maturity1);
        for(int i = 0; i < (w.ws_row); i++)
        {
            for(int j = 0; j < w.ws_col; j++)
            {
                cout << pond[i][j];
            }
        }
        cout << endl;

        pond[10][timeMaster] = "A";

        usleep(640000);
        timeMaster++;
    }


    system("setterm -cursor on");

    return 0;
}
