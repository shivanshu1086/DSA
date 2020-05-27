#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

void union_of_two_ll(node *head1, node *head2){
    linkedlist intersection;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            intersection.insertAtEnd(head1->data);
            head1=head1->next;
            head2=head2->next;
        }
        else if (head1->data<head2->data){
            intersection.insertAtEnd(head1->data);
            head1=head1->next;
        }
        else{
            intersection.insertAtEnd(head2->data);
            head2=head2->next;
        }
    }

    while(head1!=NULL){
        intersection.insertAtEnd(head1->data);
        head1=head1->next;
    }

    while(head2!=NULL){
        intersection.insertAtEnd(head2->data);
        head2=head2->next;
    }
    
    node *temp=intersection.head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    linkedlist l;
    l.insertAtEnd(10);
    l.insertAtEnd(12);
    l.insertAtEnd(13);
    l.insertAtEnd(14);
    l.insertAtEnd(15);
    l.insertAtEnd(20);
    linkedlist p;
    p.insertAtEnd(12);
    p.insertAtEnd(14);
    p.insertAtEnd(20);
    p.insertAtEnd(22);
    intersection_of_two_ll(l.head,p.head);
    // l.print();
    cout<<endl;
    return 0;
}