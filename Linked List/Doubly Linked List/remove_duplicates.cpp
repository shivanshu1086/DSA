#include <iostream>
#include "dll.h"
using namespace std;

void delete_node(node *head, node *del){
    if(head==NULL && del==NULL){
        return;
    }

    if(head==del){
        head=del->next;
    }

    if(del->next!=NULL){
        del->next->prev=del->prev;
    }

    if(del->prev!=NULL){
        del->prev->next=del->next;
    }
    free(del);
}

node *remove_duplicates(node *head){
    //for the sorted array only
    node *curr=head;
    node *next;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            delete_node(head,curr->next);
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(4);
    dl.insertAtEnd(4);
    dl.insertAtEnd(4);
    dl.insertAtEnd(4);
    dl.insertAtEnd(6);
    dl.insertAtEnd(8);
    dl.insertAtEnd(8);
    dl.insertAtEnd(10);
    dl.insertAtEnd(12);
    dl.insertAtEnd(12);
    dl.head=remove_duplicates(dl.head);
    dl.print();
    cout<<endl;
    return 0;
}