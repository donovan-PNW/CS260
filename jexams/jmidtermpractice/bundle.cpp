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
int  findSmallest(node* head); //ALL RECURSIVE!! find smallest element of given list
int removeLargest(node* head); //find largest element and removes element
int  countX(node* head, int x); //counts and returns number of times that x appears on list
void copyOdd(node* source, node** destination); //copies only odd numbers to a new linked list

node * head    = nullptr;
node * tail    = nullptr;
node * newNode = nullptr;
node * current = nullptr;
int smallNo = 255;

int main()
{
    build();
    print();
    cout << "The smallest number in this list is: " << findSmallest(head) << endl;
    cout << "largest in list: " << removeLargest(head) << endl;
    destruct();

    return 0;
}

void build()
{
    srand(time(nullptr));
    for(int index = 0; index < 5; index++)
    {
        newNode = new node;
        newNode->data = rand() % 550 + 1;
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
//    cout << "Tail to head: \n\n ";
//    for(current = tail; current; current = current->previous)
//    {
//        cout <<"|";
//        cout << fixed;
//        cout << left;
//        cout << setw(3);
//        cout << current->data << " "; 
//
//        if(index % 10 == 0 && index != 100) //<--sloppy
//            cout << endl << " ";
//        index++;
//    }
//    cout << endl << endl;
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


//int findSmallest(node* head) //ALL RECURSIVE!! find smallest element of given list
//{
//    int currentMin = 255;
//    int tempInt = 255;
//    node * currentPointer = head;
//
//    if(currentPointer->next == nullptr)
//        return currentPointer->data; 
//    else
//    {
//        tempInt = findSmallest(currentPointer->next);
//        if(tempInt < currentMin)
//            return tempInt;
//        else
//            return currentMin;
//    }
//
//    
//
//    return currentMin;
//}






//WAYYYYY MORE EFFICIENT //TODO CAN THIS BE A VOID????? OTHERWISE I NEED MORE THAN ONE RETURN 
//VOID VOID VOID VOID VOID VOID VOID VOID
//VOID VOID VOID VOID VOID VOID VOID VOID
//VOID VOID VOID VOID VOID VOID VOID VOID
//CAN i HAVE THOSE NUMBERS OUTSIDE THE FUNCTION?
//IS THERE ANY WAY TO KEEP THESE INTS IN THE FUNCTION???

//int runningSmallest = 255; //THESE ARE OUTSIDE THE FUNCTION!!!!
//int thisNumber = 255;
//int findSmallest(node* head) //ALL RECURSIVE!! find smallest element of given list
//{
//    thisNumber = head->data; //get data as number IMMEDIATELY
//    if(head->next == nullptr){
//        thisNumber = head->data;
//        if(thisNumber < runningSmallest)
//            runningSmallest = thisNumber;
//
//        //cout << "done! Absolute smallest: " << runningSmallest << endl; //base case!
//        return runningSmallest;
//    }
//    else
//    {
//        //cout << "thisNumber: " << thisNumber << " ";
//        if(thisNumber < runningSmallest)
//            runningSmallest = thisNumber;
//        //cout << "runningSmallest: " << runningSmallest << endl;
//        head = head->next;
//        thisNumber = findSmallest(head); //thisNumber becomes recursive function's output
//    }
//}


int bigly = 0;
int removeLargest(node* head) //is just find largest for this one
{
    if(head->next == nullptr){
        if(head->data > bigly) 
        {
            bigly = head->data; 
        }
        return head->data;
    }

    else
    {
        if(!head->previous)
            bigly = head->data;
        head = head->next;
        if(head->data > removeLargest(head))
        {
            bigly = head->data; 
        }
    }
     
    return bigly; 

}


int small = 255;
int findSmallest(node* head) //is just find largest for this one
{
    if(head->next == nullptr){
        if(head->data < small) 
        {
            small = head->data; 
        }
        return head->data;
    }

    else
    {
        if(!head->previous)
            small = head->data;
        head = head->next;
        if(head->data < findSmallest(head))
        {
            small = head->data; 
        }
    }
    
    return small; 

}






