//This program will build a list of integers using doubly linked lists
//Always adds a new node to the tail (at the end)
#include <iostream>
using namespace std;

//struct for Node
struct Node
{
	int data;
	Node *next;
	Node *prev;
};

//constants
const int SENTINEL = 999;

//main
int main()
{
	//declare pointers
	Node *head = NULL, *tail = NULL, *newNode = NULL, *curr = NULL;
	int num = 0;
	//allocate memory for newNode and populate it
	cout << "Please enter numbers. (999 to quit):";
	cin >> num;
	while(num != SENTINEL)
	{
		newNode = new Node;
		newNode->data = num;
		newNode->next = NULL;
		newNode->prev = NULL;
		//check to see if list is empty
		if(!head)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> num;
	}
	//print the list forward
	cout << "Prints the list forward:\n";
	for(curr = head; curr; curr = curr->next)
	{
		cout << curr->data << endl;
	}
	//delete all memory for the list
	curr = head;
	while(curr)
	{
		curr = curr->next;
		delete head;
		head = curr;
	}
	head = NULL;
	tail = NULL;
	curr = NULL;

	return 0;
}	
	

