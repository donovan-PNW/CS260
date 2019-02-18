#include <iostream>
#include "headers.h"

using namespace std;

node::node(): data(0), size(0), next(nullptr), prev(nullptr), head(nullptr)
{
}

node::node(const int& inSize)
{
    for(int index = 0; index<100; index++)
    {
        size = inSize;
        next = nullptr;
        prev = nullptr;
        head = nullptr;

        node* newNode = new node;
        newNode->data = rand() % 100+1;
    }
}

node::~node()
{
    node * current = head;
    while(current)
    {
        current = current->next;
        delete head;
        head = nullptr;
        head = current;
    }
    head = nullptr;
    next = nullptr;
    prev = nullptr;
}

void build()
{}

int seek()
{}

void insert()
{
    
}

void remove()
{}
