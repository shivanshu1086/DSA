#include <iostream>
#include "dll.h"
using namespace std;

void deletenode(node *&head, node *&del){
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

node *deleteAllOccurence(node *head, int x){
    if(head==NULL){
        return head;
    }

    node *curr=head;
    node *next;

    while(curr!=NULL){
        if(curr->data==x){
            next=curr->next;
            deletenode(head,curr);
            curr=next;
        }
        else{
            
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(2);
    dl.insertAtEnd(2);
    dl.insertAtEnd(10);
    dl.insertAtEnd(8);
    dl.insertAtEnd(4);
    dl.insertAtEnd(2);
    dl.insertAtEnd(5);
    dl.insertAtEnd(2);
    dl.head=deleteAllOccurence(dl.head,2);
    dl.print();
    cout<<endl;
    return 0;
}