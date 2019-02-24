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
    
    //int out0 = 0;
    //int out1 = 0;
    //int out2 = 0;
    //int out3 = 0;
    //int out4 = 0;
    //int out5 = 0;
    //int out6 = 0;
    //int out7 = 0;
    size_t timeMaster = 0;
    //while(true)//timeMaster < 10)
    //{
    //    int cent0 = rand()% slotTotal;
    //    int cent1 = rand()% slotTotal;
    //    int cent2 = rand()% slotTotal;
    //    int cent3 = rand()% slotTotal;
    //    int cent4 = rand()% slotTotal;
    //    int cent5 = rand()% slotTotal;
    //    int cent6 = rand()% slotTotal;
    //    int cent7 = rand()% slotTotal;
    //    for(int i = 0; i < slotTotal; i++)
    //    {
    //        if(i == cent0)
    //        {
    //            out0 = out0 + 4;
    //            cout << "+"; 
    //        }
    //        else if(i == cent1)
    //        {
    //            out1 = out1 + 4;
    //            cout << "+"; 
    //        }
    //        else if(i == cent2)
    //        {
    //            out2 = out2 + 4;
    //            cout << "+"; 
    //        }
    //        else if(i == cent3)
    //        {
    //            out3 = out3 + 4;
    //            cout << "*"; 
    //        }
    //        else if(i == cent4)
    //        {
    //            out4 = out4 + 4;
    //            cout << "*"; 
    //        }
    //        else if(i == cent5)
    //        {
    //            out5 = out5 + 4;
    //            cout << "*"; 
    //        }
    //        else if(i == cent6)
    //        {
    //            out6 = out6 + 4;
    //            cout << "@"; 
    //        }
    //        else if(i == cent7)
    //        {
    //            out7 = out7 + 4;
    //            cout << "@"; 
    //        }
    //        else if((rand() % 1989 == 0))
    //        {
    //            cout << "$";
    //        }
    //        else
    //        {
    //            cout << " ";
    //        }




    //    }
    //    if(out0 > 0)
    //        out0--;
    //    if(out1 > 0)
    //        out1--;
    //    if(out2 > 0)
    //        out2--;
    //    if(out3 > 0)
    //        out3--;
    //    if(out4 > 0)
    //        out4--;
    //    if(out5 > 0)
    //        out5--;
    //    if(out6 > 0)
    //        out6--;
    //    if(out7 > 0)
    //        out7--;

    //
    //    usleep(640000);
    //    timeMaster++;
    //}

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
            else if((rand() % 1989 == 0))
            {
                cout << "#";
            }
            else if((rand() % 1989 == 0))
            {
                cout << "~";
            }
            else if(i == 5000)
                cout << "U";
            else
            {
                cout << " ";
            }




        }

    
        usleep(640000);
        cout << endl;
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



    system("setterm -cursor on");

    return 0;
}
