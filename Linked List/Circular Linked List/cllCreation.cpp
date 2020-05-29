#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;



int main(){
    linkedlist l;
    l.insertAtEnd(3);
    l.insertAtEnd(6);
    l.insertAtEnd(9);
    l.insertAtEnd(15);
    l.insertAtEnd(30);
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    
    //print
    temp=l.head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=l.head);
    cout<<endl;
    return 0;
}