#include <iostream>
#include "dll.h"
using namespace std;

node *insertion_at_front(node *head, int x){
    node *temp=new node(x);
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

node *insertion_at_given_pos(node *head, int x, int pos){
    node *temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    node *temp2=new node(x);
    temp2->next=temp->next;
    temp->next->prev=temp2;
    temp->next=temp2;
    temp2->prev=temp;
    return head;
}

node *insertion_at_the_end(node *head, int x){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *ñ=new node(x);
    temp->next=ñ;
    ñ->prev=temp;
    return head;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(3);
    dl.insertAtEnd(5);
    dl.insertAtEnd(7);
    dl.insertAtEnd(10);
    dl.print();
    cout<<endl<<"After adding: "<<endl;
    // dl.head=insertion_at_front(dl.head,17);
    // dl.head=insertion_at_given_pos(dl.head,17,4);
    dl.head=insertion_at_the_end(dl.head,17);
    dl.print();
    cout<<endl;
    return 0;
}