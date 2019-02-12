#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

struct node
{
    int data;
    node * previous;
    node * next;
};

void build();
void print();
void destruct();
int  findSmallest(node* head);
void removeLargest(node* head);
int  countX(node* head, int x);
void copyOdd(node* source, node** destination);

node * head    = nullptr;
node * tail    = nullptr;
node * newNode = nullptr;
node * current = nullptr;

int main()
{
    build();
    print();
    destruct();

    return 0;
}

void build()
{
    srand(time(nullptr));
    for(int index = 0; index < 100; index++)
    {
        newNode = new node;
        newNode->data = rand() % 100 + 1;
        newNode->previous = nullptr;
        newNode->next = nullptr;
        if(!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
}

void print()
{
    int index = 1;
    cout << "\nList printed head to tail:\n\n";
    //cout << " -------------------------------------------------\n";
    cout << " ";
    for(current = head; current; current = current->next)
    {
        cout << fixed;
        cout << right;
        cout << setw(3);
        cout << current->data <<  "| "; 
        if(index % 10 == 0 && index != 100) //<--sloppy
            cout << endl << " ";
        index++;
    }
    cout << endl << endl;

    index = 1;
    cout << "Tail to head: \n\n ";
    for(current = tail; current; current = current->previous)
    {
        cout <<"|";
        cout << fixed;
        cout << left;
        cout << setw(3);
        cout << current->data << " "; 

        if(index % 10 == 0 && index != 100) //<--sloppy
            cout << endl << " ";
        index++;
    }
    cout << endl << endl;
}

void destruct()
{
    current = head;
    while(current)
    {
        current = current->next;
        delete head;
        head = current;
    }
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}




















