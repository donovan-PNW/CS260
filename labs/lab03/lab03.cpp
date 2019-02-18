#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{

    double startBalance = 0;
    double interestRate = 0;
    double numberOfYears = 0;

    cout << endl;
    cout << "Enter starting balance: ";
    cin >> startBalance;
    cout << "Enter interest rate: ";
    cin >> interestRate;
    cout << "Enter number of years: ";
    cin >> numberOfYears;
    cout << endl;
     

    cout << fixed;
    cout << showpoint;
    cout << setw(5);
    //cout << setprecision(9);
    for(int yearNumber = 1; yearNumber <= numberOfYears; yearNumber++)
    {
        cout << "Year " << yearNumber << " " << " $";
        cout << startBalance * pow((1 + (interestRate / 100)), yearNumber) << endl;
    }

    cout << endl;
    return 0;
}
