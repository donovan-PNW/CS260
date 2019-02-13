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
int  findLargest(node* head); //ALL RECURSIVE!! find smallest element of given list
node *removeLargest(node* current, node* topNode, int champion); //find largest element and removes element
//node* removeLargest(node* head); //find largest element and removes element
int  countX(node* head, int x); //counts and returns number of times that x appears on list
void copyOdd(node* source, node** destination); //copies only odd numbers to a new linked list
void everyOtherNode(node* head);

node * head    = nullptr;
node * tail    = nullptr;
node * newNode = nullptr;
node * current = nullptr;
int smallNo = 255;

int main()
{
    build();
    tail->data = 11;
    print();
    //cout << "The smallest number in this list is: " << findSmallest(head) << endl;
    //cout << "largest in list: " << findLargest(head) << endl;
    node *deletePointer = removeLargest(head, head, 0);
    cout << "node to delete: " << deletePointer << endl; 
    print();

    //int deleteNumber = deletePointer->data; 
    //cout << "largest to remove: " << deleteNumber << endl;
    //cout << "every other node: " << endl;
    //everyOtherNode(head);
    //cout << "Number of times 3 occurred in list: "
    //<< countX(head, 3) << endl;

    destruct();

    return 0;
}

void build()
{
    srand(time(nullptr));
    for(int index = 0; index < 8; index++)
    {
        newNode = new node;
        newNode->data = rand() % 5 + 1;
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


//int bigly = 0;
//int removeLargest(node* head) //is just find largest for this one
//{
//    if(head->next == nullptr){
//        if(head->data > bigly) 
//        {
//            bigly = head->data; 
//        }
//        return head->data;
//    }
//
//    else
//    {
//        if(!head->previous)
//            bigly = head->data;
//        head = head->next;
//        if(head->data > removeLargest(head))
//        {
//            bigly = head->data; 
//        }
//    }
//     
//    return bigly; 
//
//}


//int small = 255;
//int findSmallest(node* head) //is just find largest for this one
//{
//    if(head->next == nullptr){
//        if(head->data < small) 
//        {
//            small = head->data; 
//        }
//        return head->data;
//    }
//
//    else
//    {
//        if(!head->previous)
//            small = head->data;
//        head = head->next;
//        if(head->data < findSmallest(head))
//        {
//            small = head->data; 
//        }
//    }
//    
//    return small; 
//}


int findSmallest(node* head)
{
    int thisNumber = head->data;
    if(head->next == nullptr)
    {
        return head->data;
    }
    else
    {
        int nextNumber = findSmallest(head->next);
        int winner;
        if(thisNumber < nextNumber) 
            winner = thisNumber;
        else
            winner = nextNumber;
        return winner;
    }

}


//SEE NEXT FUNCTION BELOW
//int counter = 0;
//void everyOtherNode(node* head)
//{
//    if(head==nullptr){
//        cout << endl;
//        return;
//    }
//
//    if(counter % 2 != 0)
//    {
//        cout << head->data << " ";
//    }
//    counter++;
//    head = head->next;
//    everyOtherNode(head);
//}

//NODE YOU NEED AN IF FOR HEAD==NULLPRT AND ANOTHER IFF FOR HEAD->NEXT == NULLPTR
//BECAUSE ODDS AND EVENS ACT DIFFERENTLY
void everyOtherNode(node* head)
{
    if(head==nullptr){
        cout << endl << endl;;
        return;
    }
    cout << head->data << " ";
    if(head->next != nullptr)
    {
        everyOtherNode(head->next->next);
    }
    else
        cout << endl << endl;
    cout << head->data << " ";
}




int countX(node* head, int inNumber)
{
    int valToReturn = 0;
    if(head != nullptr){
        if(head->data == inNumber)
        {
            valToReturn = countX(head->next, inNumber) + 1;
            cout << valToReturn << " ";
        }
        else
        {
            valToReturn = countX(head->next, inNumber);
            cout << "Z ";
        }

    }
    return valToReturn;
}

int findLargest(node* thisNode)
{
    int biggestNumber = 0;
    if(thisNode != nullptr)
    {
        int nextNumber = findLargest(thisNode->next);
        if(thisNode->data > nextNumber)
            biggestNumber = thisNode->data;
        else
            biggestNumber = nextNumber;
    }
    return biggestNumber;

}



//node* removeLargest(node* thisNode)
//{
//    node* biggest = head;
//    if(thisNode != nullptr)
//    {
//        //int nextNumber = removeLargest(thisNode->next);
//        //cout << "thisNumber: " << thisNode->data << " nextNumber: " << nextNumber << endl;
//        node* runningNode = removeLargest(thisNode->next);  
//        if(thisNode->data > runningNode->data)
//        {
//            biggest = thisNode;
//            cout << &thisNode << endl;
//            cout << &biggest << endl;
//            cout << "New high score: ";
//            cout << "biggestNode data: " <<  thisNode->data << endl;
//        }
//        else
//            biggest = runningNode; 
//            //biggestNumber = nextNumber;
//    }
//
//    //cout << &biggest;
//    return biggest;
//    //return biggest-> data;
//
//}




//OR: TRY int removeLargest(node* thisNode, int largestNo)

node* removeLargest(node* current, node* topNode, int champion)
{
    if(current == nullptr)
    {
        cout << "final big number:   " << champion << endl;
        cout << "all time top:       " << topNode<< endl;    
        node* throwAway = topNode;
        if(!topNode->previous)
        {
            cout << "beginning" << endl; 
            node* extraThrowaway = topNode;
            head = head->next;
            delete topNode;
            head->previous = nullptr;
        }
        if(!topNode->next)
        {
            cout << "end" << endl; 
            topNode->previous->next = nullptr;
            tail = topNode->previous;
            delete topNode;
            topNode = nullptr;
        }
        else if(topNode->previous && topNode->next)
        {
            cout << "middle: " << endl;
            //node* throwAway = topNode;
            topNode->previous->next = topNode->next;
            topNode->next->previous = topNode->previous;
            delete topNode;
            topNode = nullptr;
            //cout << "middle: " << endl;
            //node * current = topNode->previous;
            //node *extraFuckingNodeBecauseWhytheFuckNot = topNode;
            //topNode = topNode->next;
            //delete extraFuckingNodeBecauseWhytheFuckNot;
            //extraFuckingNodeBecauseWhytheFuckNot = nullptr;
            /////topNode->next->previous = topNode->previous;
            /////delete topNode;
            /////topNode = nullptr;
        }
        return throwAway;
    }
    else
    {
        cout << "this number:  " << current->data << endl;
        if(current->data > champion)
        {
            champion = current->data;
            topNode = current;
            cout << "this address: " << current << endl;
            cout << "topNode:      " << topNode << endl;
            removeLargest(current->next, topNode, champion);
        }
        else
            removeLargest(current->next, topNode, champion);
    }
}




