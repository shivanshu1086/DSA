#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *swapXY(node *head, int x, int y){
    node *prevX=NULL,*currX=head;
    while(currX && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }

    node *prevY=NULL,*currY=head;
    while(currY && currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }

    //if anyone of these are not present
    if(currX==NULL || currY==NULL){
        return head;
    }

    if(prevX!=NULL){
        prevX->next=currY;
    }
    else{
        head=currY;
    }

    if(prevY!=NULL){
        prevY->next=currX;
    }
    else{
        head=currX;
    }

    //swappinng
    node *temp=currY->next;
    currY->next=currX->next;
    currX->next=temp;

    // swap(*a, *b); 
    // swap(((*a)->next), ((*b)->next)); //another way

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
    int x=12,y=20;
    l.head=swapXY(l.head,x,y);
    l.print();
    cout<<endl;
    return 0;
}