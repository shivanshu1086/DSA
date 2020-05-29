#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *insert_in_sorted_cll(node *head, int x){
    node *firstnode=head;
    node *secondnode=NULL;

    while(firstnode->data<x && firstnode->next!=head){
        secondnode=firstnode;
        firstnode=firstnode->next;
    }
    if(firstnode->next==head){
        node *temp=new node(x);
        firstnode->next=temp;
        temp->next=head;
        return head;
    }//if it is greatest
    if(firstnode->data>x && firstnode==head){
        node *temp=new node(x);
        temp->next=head;
        head=temp;
        temp=head;
        do{
            temp=temp->next;
        }
        while(temp->next!=head->next);
        temp->next=head;
        return head;
    }//if it is smallest
    
    node *temp=new node(x);
    secondnode->next=temp;
    temp->next=firstnode;
    return head;
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
    l.head=insert_in_sorted_cll(l.head,8);
    l.print();
    cout<<endl;
    return 0;
}