#include <iostream>
#include "dll.h"
using namespace std;

node *split(node *head){
    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    node *temp=slow->next;
    slow->next=NULL;
    return temp;
}

node *merge(node *first, node *second){
    if(!first){
        return second;
    }
    if(!second){
        return first;
    }

    if(first->data<second->data){
        first->next=merge(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }
    else{
        second->next=merge(first,second->next);
        second->next->prev=second;
        second->prev=NULL;
        return second;
    }
}

node *merge_sort(node *head){
    if(!head || !head->next){
        return head;
    }
    node *second=split(head);
    head=merge_sort(head);
    second=merge_sort(second);

    return merge(head, second);
}

int main(){
    dlinkedlist dl;
    // for(int i=8;i>=1;i--){
    //     dl.insertAtEnd(i);
    // }
    dl.insertAtEnd(5);
    dl.insertAtEnd(20);
    dl.insertAtEnd(4);
    dl.insertAtEnd(3);
    dl.insertAtEnd(30);
    dl.insertAtEnd(10);
    dl.head=merge_sort(dl.head);
    dl.print();
    cout<<endl;
    return 0;
}