#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *delete_node(node *head, int x){
    node *firstnode=head;
    node *secondnode=NULL;

    while(firstnode->next!=head && firstnode->data!=x){
        secondnode=firstnode;
        firstnode=firstnode->next;
    }

    if(firstnode->next==head && firstnode->data==x){
        secondnode->next=head;
        delete firstnode;
        return head;
    }

    if(firstnode->data==x && firstnode==head){
        head=head->next;
        secondnode=head;
        while(secondnode->next!=firstnode){
            secondnode=secondnode->next;
        }
        secondnode->next=head;
        delete firstnode;
        return head;
    }

    if(firstnode->data==x && firstnode!=head && firstnode->next!=head){
        secondnode->next=firstnode->next;
        delete firstnode;
        return head;
    }
    return head;
}

int main(){
    linkedlist l;
    l.insertAtEnd(2);
    l.insertAtEnd(5);
    l.insertAtEnd(7);
    l.insertAtEnd(8);
    l.insertAtEnd(10);
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    l.head=delete_node(l.head,7);
    l.print();
    cout<<endl;
    return 0;
}