#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <random>

using namespace std;

class node 
{
    private:
        int data;
        int size;
        node *next;
        node *prev;
        node* head; 

    public:
        node();
        node(node& otherNode)=delete;
        node operator=(node& otherNode)=delete;
        node(const int& size);
        ~node();
        void build();
        void insert();
        void remove();
        int seek();
};






#endif
