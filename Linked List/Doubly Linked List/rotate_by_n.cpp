#include <iostream>
#include "dll.h"

using namespace std;

node *rotate_by_n(node *head, int n){
    node *prev_head=head;
    node *prev_tail=head;
    int count=1;
    while(count<n){
        prev_tail=prev_tail->next;
        count++;
    }

    head=prev_tail->next;
    prev_tail->next->prev=NULL;
    prev_tail->next=NULL;

    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=prev_head;
    temp->next->prev=temp;

    return head;
}

int main()
{
    dlinkedlist dl;
    dl.insertAtEnd(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(3);
    dl.insertAtEnd(4);
    dl.insertAtEnd(5);
    dl.print();
    cout<<endl<<endl;
    dl.head=rotate_by_n(dl.head,2);
    dl.print();
    cout<<endl;
    return 0;
}
