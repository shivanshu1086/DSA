#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *reverseTheLL(node *head){
    node *prev,*curr,*next;
    prev=NULL;
    next=NULL;
    curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    linkedlist l;
    l.insertAtEnd(3);
    l.insertAtEnd(6);
    l.insertAtEnd(9);
    l.insertAtEnd(15);
    l.insertAtEnd(30);
    l.head=reverseTheLL(l.head);
    l.print();
    cout<<endl;
    return 0;
}