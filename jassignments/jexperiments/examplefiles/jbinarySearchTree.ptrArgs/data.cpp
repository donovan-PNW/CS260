#include "data.h"
#include <iostream>
#include <iomanip>

using namespace std;

data::data(char ch) : ch(ch)
{
}

bool operator<(const data& d1, const data& d2)
{
	return d1.ch < d2.ch;
}

bool operator==(const data& d1, const data& d2)
{
	return d1.ch == d2.ch;
}

ostream& operator<<(ostream& out, const data& d)
{
	out << d.ch;
	return out;
}