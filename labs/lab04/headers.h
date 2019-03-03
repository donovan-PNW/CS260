#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>

using namespace std;

void borders();

class dataSet
{
    private:
        int count[20];
        int tally = 0;
    public:
        dataSet();
        ~dataSet();
        dataSet(dataSet& otherDataSet)=delete;
        dataSet operator=(dataSet& otherDataSet)=delete;
        void addNumber(int& number);
        int numberQuery(int& number);
};

class barCharter
{
    private:
        dataSet myData;

    public:
        barCharter();
        ~barCharter();
        barCharter(barCharter& otherBarChart)=delete;
        barCharter operator=(barCharter& otherBarChart)=delete;
        void inPutter();
        void outPrinter();

};





#endif
