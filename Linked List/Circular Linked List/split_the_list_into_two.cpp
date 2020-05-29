#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

void split_the_list_into_two(node *head){
    node *slowptr=head,*fastptr=head;
    while(fastptr->next->next!=head && fastptr->next!=head){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    if(fastptr->next->next==head){
        fastptr=fastptr->next;
    }
    node *secondhead=slowptr->next;
    slowptr->next=NULL;
    fastptr->next=NULL;
    node *firsthead=head;
    cout<<"First list: ";
    while(firsthead!=NULL){
        cout<<firsthead->data<<" ";
        firsthead=firsthead->next;
    }
    cout<<endl<<"Second list: ";
    while(secondhead!=NULL){
        cout<<secondhead->data<<" ";
        secondhead=secondhead->next;
    }
}

int main(){
    linkedlist l;
    l.insertAtEnd(3);
    l.insertAtEnd(6);
    l.insertAtEnd(9);
    l.insertAtEnd(15);
    
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    split_the_list_into_two(l.head);
    cout<<endl;
    return 0;
}