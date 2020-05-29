#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *exchange_first_last(node *head){
    node *temp2=head;
    while(temp2->next->next!=head){
        temp2=temp2->next;
    }
    temp2->next->next=head->next;
    head->next=temp2->next;
    temp2->next=head;
    head=head->next;
    return head;
}

int main(){
    linkedlist l;
    int n=14,m=2;
    for(int i=1;i<=n;i++){
        l.insertAtEnd(i);
    }
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    l.print();
    cout<<endl;
    l.head=exchange_first_last(l.head);
    l.print();
    cout<<endl;
    return 0;
}