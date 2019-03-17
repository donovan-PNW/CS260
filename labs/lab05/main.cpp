#include <iostream>
#include "functions.h"

using namespace std;

void getValues(int& x,int& y) {
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;
    lineEnder();
}


int main() {

  int choice;
  bool done = false;
  int x,y;

  cout << "Welcome to the math functionator!" << endl << endl;

  do {
    cout << "1) GCD" << endl;
    cout << "2) LCM" << endl;
    cout << "3) average" << endl;
    cout << "4) factorial between two values" << endl;
    cout << "0) quit" << endl;
    cout << "Enter choice: ";

    cin >> choice;

    if (choice != 0) {
	getValues(x,y);
    }
    
    switch (choice) {
	case 1:
        cout << "Greatest common denominator: " << doGCD(x,y) << endl;
        lineEnder();
	    break;
	case 2:
	    doLCM(x,y);
        lineEnder();
	    break;
	case 3:
	    doAverage(x,y);
        lineEnder();
	    break;
	case 4:
	    factorial(x,y);
        lineEnder();
	    break;
	case 0:
	    done = true;
        break;
    default:
        cout << "not an option! Try again";
        lineEnder();
    }
  } while (!done);
  
  cout << "Bye" << endl;

  return(0);
}
