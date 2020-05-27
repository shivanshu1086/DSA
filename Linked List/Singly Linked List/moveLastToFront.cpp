#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *moveLastToFront(node *head){
    node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node *temp2=temp->next;
    temp->next=NULL;
    temp2->next=head;
    head=temp2;

    return head;
}

int main(){
    linkedlist l;
    l.insertAtEnd(10);
    l.insertAtEnd(15);
    l.insertAtEnd(12);
    l.insertAtEnd(13);
    l.insertAtEnd(20);
    l.insertAtEnd(14);
    l.head=moveLastToFront(l.head);
    l.print();
    cout<<endl;
    return 0;
}