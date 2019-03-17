#include "functions.h"

using namespace std;

int doGCD(int x, int y)
{
    if(x == 0 || y == 0)
    {
        return 0;
    }
    else if(x == y)
    {
        return x;
    }
    else if(x >= y)
    {
        return doGCD((x - y), y);
    }
    else if(x < y)
    {
        return doGCD(x, (y - x));
    }
}
void doLCM(int x, int y)
{
    cout << "Least common multiple: " << (x * y)/(doGCD(x,y)) << endl;
}
void doAverage(int x, int y)
{
    int sum = x + y;
    int average = sum/2;
    cout << "Average of " << x << " and " << y << " is " << average << endl;
}

void factorial(int x, int y)
{
    int z;
    if(x >= y)
        z = x - y;
    else
        z = y - x;
    cout << "difference: " << z << endl;
    if(z > 20)
        cout << "Overflow! Difference is too large. You broke c++" << endl;
    else
        cout << "factorial of difference: " << factorialHelper(z) << endl;
}

size_t factorialHelper(int z)
{
    if(z == 1)
        return z;
    else
        return (z * factorialHelper(z-1));
}

void lineEnder()
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}





