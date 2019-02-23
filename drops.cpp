#include <iostream>
//#include <cstdlib> //not necessary probably but why not
#include <ctime>
#include <chrono>
#include <random>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(nullptr));
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    int slotTotal = w.ws_row * w.ws_col;
    cout << "slotTotal" << slotTotal << endl;

    char letter = 'A';
    for(int i = 0; i < w.ws_row; i++)
    {
        for(int j=0; j < w.ws_col; j++)
        {
            cout << static_cast<char>(letter + (i-1));
        }
    }
    
    usleep(640000);

    for(int i = 0; i < w.ws_row; i++)
    {
        for(int j=0; j < w.ws_col; j++)
        {
            cout << static_cast<char>(letter + (i-1));
        }
    }

    system("setterm -cursor off");
    
    int timeMaster = 0;
    while(true)//timeMaster < 10)
    {
        int cent0 = rand()% slotTotal;
        int cent1 = rand()% slotTotal;
        int cent2 = rand()% slotTotal;
        int cent3 = rand()% slotTotal;
        int cent4 = rand()% slotTotal;
        int cent5 = rand()% slotTotal;
        int cent6 = rand()% slotTotal;
        int cent7 = rand()% slotTotal;
        for(int i = 0; i < slotTotal; i++)
        {
            if((i == cent0) || (i == cent1) || (i == cent2))
            {
                cout << "+"; 
            }
            else if((i == cent3) || (i == cent4) || (i == cent5))
            {
                cout << "*"; 
            }
            else if((i == cent6) || (i == cent7))
            {
                cout << "@"; 
            }
            else if((rand() % 1989 == 0))
            {
                cout << "$";
            }
            else
            {
                cout << " ";
            }




        }

    
        usleep(640000);
        timeMaster++;
    }




    //for(int i = 0; i < 55; i++)
    //{
    //    for(int j=0; j < 212; j++)
    //    {
    //        cout << static_cast<char>(letter + (i-1));
    //    }
    //
    //}

    //for


    system("setterm -cursor on");

    return 0;
}
