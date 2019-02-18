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
void print(node* estEhead);
void destruct();
int  findSmallest(node* head); //ALL RECURSIVE!! find smallest element of given list
int  findLargest(node* head); //ALL RECURSIVE!! find smallest element of given list
node *removeLargest(node* current, node* topNode, int champion); //find largest element and removes element
//node* removeLargest(node* head); //find largest element and removes element
int  countX(node* head, int x); //counts and returns number of times that x appears on list
//copies only odd numbers to a new linked list
//node* everyOtherNode(node* source, node* fromNode, node* toNode, node * copyHead , int ticker);
node* everyOtherNode(node* source, node* destination);

node * head    = nullptr;
node * tail    = nullptr;
node * newNode = nullptr;
node * current = nullptr;
int smallNo = 255;

int main()
{
    int tickerStart = 0;
    node * duplicateHead = nullptr;
    build();
//    head->data = 11;
    print(head);
    
    duplicateHead = everyOtherNode(head, duplicateHead);
    //duplicateHead = everyOtherNode(head, duplicateHead, nullptr, nullptr, tickerStart);
    cout << "dupehead " << duplicateHead << endl;
    //node *deletePointer = removeLargest(head, head, 0);
    //cout << deletePointer << endl;
   // cout << "node to delete: " << deletePointer << endl; 
    print(duplicateHead);

    //int deleteNumber = deletePointer->data; 
    //cout << "largest to remove: " << deleteNumber << endl;
    //cout << "every other node: " << endl;
    //cout << "Number of times 3 occurred in list: "
    //<< countX(head, 3) << endl;

    destruct();

    return 0;
}

void build()
{
    //srand(time(nullptr));
    for(int index = 0; index < 8; index++)
    {
        newNode = new node;
        newNode->data = index; //rand() % 5 + 1;
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

void print(node* estEhead)
{
    int index = 1;
    cout << "\nList printed head to tail:\n\n";
    cout << " ";
    for(current = estEhead; current; current = current->next)
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
    //index = 1;
    //cout << "Tail to head: \n\n ";
    //for(current = tail; current; current = current->previous)
    //{
    //    cout <<"|";
    //    cout << fixed;
    //    cout << left;
    //    cout << setw(3);
    //    cout << current->data << " "; 

    //    if(index % 10 == 0 && index != 100) //<--sloppy
    //        cout << endl << " ";
    //    index++;
    //}
    //cout << endl << endl;

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
            topNode->previous->next = topNode->next;
            topNode->next->previous = topNode->previous;
            delete topNode;
            topNode = nullptr;
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

node* everyOtherNode(node * source, node * destination)
{
 
    if(source->next)
    {
        node* newdestination;
        if((source->next != nullptr && source->next->next))
        {
            newdestination = new node;
            newdestination->data = source->data;
            cout << "CHECKPOINT " << endl;
            newdestination->next = everyOtherNode(source->next->next, nullptr);
        }
        //else
        //    newdestination = nullptr;
            //delete newdestination;
            //newdestination->next = nullptr;
        return newdestination;
    }

 
}
//node* everyOtherNode(node* source, node* fromNode, node* toNode, node* copyNode, int ticker)
//{
//    if(source)
//    {
//    
//    
//    cout << "first if" << endl;
//    if(fromNode == nullptr)
//    {
//        if(ticker == 0)
//        {
//            node* newDestination = new node;
//            newDestination->data = source->data;
//            newDestination->previous = nullptr;
//            newDestination->next = nullptr;
//            ticker++;
//            cout << "firstNewDestination->data: "  << newDestination->data << endl;
//            source = source->next;
//            fromNode = newDestination;
//            cout << "fromNode: " << &fromNode << endl;;
//            fromNode = fromNode->next;
//            toNode = toNode->next;
//            homeNode = everyOtherNode(source, fromNode, toNode, homeNode, ticker);
//            homeNode = newDestination;
//            cout << "HOME NODE " << homeNode << endl;
//        }
//        else if(source->next != nullptr)
//        {
//            if(ticker %2 == 0){
//            node* newDestination = new node;
//            newDestination->data = source->data;
//            newDestination->next = next
//            ticker++;
//            cout << "Destination->data: "  << newDestination->data << endl;
//            source = source->next;
//            backDestination = destinationCurrent; 
//            destinationCurrent = newDestination;
//            homeNode = everyOtherNode(source, destinationCurrent, backDestination, homeNode, ticker);
//            }
//            else
//            {
//                ticker++;
//                cout << "checkpoint 5" << endl;
//                source = source->next;
//
//                homeNode = everyOtherNode(source, destinationCurrent, backDestination, homeNode, ticker);
//            }
//            
//        }
//        
//    }
//
//    }
//    return homeNode;
//
//}






















