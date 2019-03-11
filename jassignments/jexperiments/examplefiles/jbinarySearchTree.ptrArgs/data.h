#ifndef DATA_H
#define DATA_H
#include <iostream>

using namespace std;

class data
{
public:
	data(char ch);

	friend bool operator< (const data& d1, const data& d2);
	friend bool operator== (const data& d1, const data& d2);
	friend ostream& operator<<(ostream& out, const data& d);

	friend class BST;

private:
	char	ch;
};


#endif