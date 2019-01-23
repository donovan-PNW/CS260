#include "linkedlist.h"
//shouldn't these just be included from the header file?
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

linkedList::linkedList() : head(nullptr), listSize(0)
{
}

linkedlist::linkedlist
