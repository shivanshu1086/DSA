#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

int intersecting_point(linkedlist l, linkedlist p){
    int x=l.length(l.head);
    int y=p.length(p.head);
    int d=abs(x-y);
    node *temp;
    if(x>y){//only if first list is bigger than second
        temp=l.head;
        while(d-- && temp!=NULL){
            temp=temp->next;
        }
        node *temp2=p.head;
        while(temp!=NULL && temp2!=NULL){
            if(temp->data==temp2->data){
                return temp->data;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        return -1;
    }
    return -1;
}

int main(){
    linkedlist l;
    l.insertAtEnd(3);
    l.insertAtEnd(6);
    l.insertAtEnd(9);
    l.insertAtEnd(15);
    l.insertAtEnd(30);
    linkedlist p;
    p.insertAtEnd(10);
    p.head->next=l.head->next->next->next;
    cout<<intersecting_point(l,p);
    // l.print();
    cout<<endl;
    return 0;
}