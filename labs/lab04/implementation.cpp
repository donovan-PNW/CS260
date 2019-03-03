#include "headers.h"
#include <iostream>

using namespace std;

int main()
{
    borders();
    barCharter thisChart;
    thisChart.inPutter();
    thisChart.outPrinter();
    borders();




    return 0;
}

dataSet::dataSet()
{
    for(int i = 0; i < 20; i++)
    {
        count[i] = 0;
    }
}

dataSet::~dataSet()
{
}

void dataSet::addNumber(int& number)
{
    //std::cout << number << endl;
    count[tally] = number;

    //for(int i = 0; i < 10; i++)
    //{
    //    std::cout << count[i] << endl;
    //}
    tally++;
}

int dataSet::numberQuery(int& number)
{
    return count[number];
}

barCharter::barCharter()
{
}

barCharter::~barCharter()
{
}

void barCharter::inPutter()
{
    int howMany;
    int thisNumber;
    cout << "How many numbers would you like to enter?\n";
    cin >> howMany;
    while(cin.fail() || howMany <= 0 || howMany > 20)
    {
        cout << "ERROR: Not in bounds!! Please enter a positive integer between 1 and 20" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> howMany;
    }
    for(int index = 0; index < howMany; index++)
    {
        cout << "Enter a number between 0 and 10 (including 10): ";
        cin >> thisNumber;
        while(cin.fail() || thisNumber < 0 || thisNumber > 10)
        {
            cout << "ERROR: Not in bounds!! please enter a number between 1 and 10" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> thisNumber;;
        }
        myData.addNumber(thisNumber);
    }
}

//void barCharter::outPrinter()
//{
//    std::cout << "\n\n\n\n\n";
//    int outNumber = 0;
//    for(int i = 0; i < 20; i++)
//    {
//        outNumber = myData.numberQuery(i);
//        for(int i = 0; i < outNumber; i++)
//        {
//            std::cout << '*';
//
//        }
//        if(outNumber != 0)
//            std::cout << endl;
//        //std::cout << outNumber << endl;
//    }
//}

void barCharter::outPrinter()
{
    int lineNo;
    int currentOutNumber;
    for(lineNo = 10; lineNo > 0; lineNo--)
    {
        for(int j = 0; j < 20; j++)
        {
            currentOutNumber = myData.numberQuery(j);
            if((currentOutNumber - lineNo) >= 0)
            {
                std::cout << '*';
            }
            else
                std::cout << ' ';
        }
        std::cout << endl;
    }
}

void borders()
{
    std::cout << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    std::cout << endl;
    std::cout << endl;
}























