#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

bool is_circular_or_not(node *head){
    node *temp=head;
    while(temp!=head && temp!=NULL){
        temp=temp->next;
    }
    return (temp==head);
}

int main(){
    linkedlist l;
    l.insertAtEnd(3);
    l.insertAtEnd(7);
    l.insertAtEnd(9);
    l.insertAtEnd(11);
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    cout<<boolalpha<<is_circular_or_not(l.head);
    // l.print();
    cout<<endl;
    return 0;
}