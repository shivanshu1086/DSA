#include <iostream>
#include "dll.h"

using namespace std;

void push(node** head_ref, node* new_node) 
{ 
    // since we are adding at the beginning, 
    // prev is always NULL 
    new_node->prev = NULL; 
   
    // link the old list off the new node 
    new_node->next = (*head_ref); 
   
    // change prev of head node to new node 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
   
    // move the head to point to the new node 
    (*head_ref) = new_node; 
} 

node *revListInGroupOfGivenSize(node *head, int k){
    node *curr=head;
    // dlinkedlist newll;
    node *next=NULL;
    node *newHead=NULL;
    int count=0;

    //reversing
    while(curr!=NULL && count<k){
        next=curr->next;
        push(&newHead,curr);
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=revListInGroupOfGivenSize(next,k);
        head->next->prev=head;
    }

    return newHead;
}


int main()
{
    dlinkedlist dl;
    dl.insertAtEnd(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(3);
    dl.insertAtEnd(4);
    dl.insertAtEnd(5);
    // dl.insertAtEnd(6);
    dl.print();
    cout<<endl<<endl;
    dl.head=revListInGroupOfGivenSize(dl.head,2);
    dl.print();
    cout<<endl;
    return 0;
}
