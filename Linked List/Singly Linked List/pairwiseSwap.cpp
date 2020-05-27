#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *pairwiseSwap(node *head){
    node *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
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
    l.head=pairwiseSwap(l.head);
    l.print();
    cout<<endl;
    return 0;
}