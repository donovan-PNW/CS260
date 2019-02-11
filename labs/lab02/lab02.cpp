#include <iostream>

using namespace std;

int ascendingNumber = 1;
int descendingNumber = 100;
void printAscending();
void printDescending();

int main()
{
    cout << "Ascending: " << endl;
    printAscending();
    cout << endl << "Descending " << endl;
    printDescending();

    return 0;
}

void printAscending()
{
    cout << ascendingNumber << " ";
    ascendingNumber++;
    if(ascendingNumber < 101)
        printAscending();
    else
        cout << endl << endl;
    return;
}

void printDescending()
{
    cout << descendingNumber << " ";
    descendingNumber--;
    if(descendingNumber > 0)
        printDescending();
    else
    {
        cout << endl << endl;
    }
    return;
}
