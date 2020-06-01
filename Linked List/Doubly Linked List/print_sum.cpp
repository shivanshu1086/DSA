#include <iostream>
#include "dll.h"
using namespace std;

void print_sum(node *head, int x){
    node *temp=head;
    while(temp->data<x){
        temp=temp->next;
    }

    while(temp->prev!=NULL){
        node *temp2=head;
        while(temp2->next!=temp){
            if(temp->data+temp2->data==x){
                cout<<"("<<temp->data<<","<<temp2->data<<")"<<" ";
            }
            temp2=temp2->next;
        }
        temp=temp->prev;
    }
}

int main(){
    dlinkedlist dl;
    for(int i=1;i<=9;i++){
        dl.insertAtEnd(i);
    }
    print_sum(dl.head,9);
    // dl.print();
    cout<<endl;
    return 0;
}