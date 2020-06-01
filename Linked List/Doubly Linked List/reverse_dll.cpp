#include <iostream>
#include "dll.h"
using namespace std;

node *reverse_dll(node *head){
    node *temp=NULL;
    node *curr=head;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    return temp->prev;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(3);
    dl.insertAtEnd(5);
    dl.insertAtEnd(7);
    dl.insertAtEnd(10);
    dl.print();
    printf("\nAfter reversing the linked list: \n");
    dl.head=reverse_dll(dl.head);
    dl.print();
    cout<<endl;
    return 0;
}