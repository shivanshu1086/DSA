#include <iostream>
#include "dll.h"
using namespace std;

node *insert_in_sortedLL(node *head, int x){
    node *temp=head;
    node *temp_pre;
    while(temp->data<x && temp->next!=NULL){
        temp_pre=temp;
        temp=temp->next;
    }

    if(temp==head){
        node *new_node=new node(x);
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return head;
    }


    if(temp->next==NULL){
        node *new_node=new node(x);
        new_node->prev=temp;
        temp->next=new_node;
        return head;
    }


    node *new_node=new node(x);
    new_node->next=temp;
    new_node->prev=temp_pre;
    temp_pre->next=new_node;
    temp->prev=new_node;
    return head;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(3);
    dl.insertAtEnd(5);
    dl.insertAtEnd(8);
    dl.insertAtEnd(10);
    dl.insertAtEnd(12);
    dl.print();
    dl.head=insert_in_sortedLL(dl.head,22);
    cout<<endl<<endl;
    dl.print();
    cout<<endl;
    return 0;
}