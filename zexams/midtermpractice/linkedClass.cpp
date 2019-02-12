#include <iostream>
using namespace std;


struct Node* head = NULL; 
void insert(int newdata) { 
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data  = newdata; 
   newnode->prev = NULL; 
   newnode->next = head;     
   if(head !=  NULL) 
      head->prev = newnode ;     
   head = newnode; 
}   
