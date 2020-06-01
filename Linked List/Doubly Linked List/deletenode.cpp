#include <iostream>
#include "dll.h"
using namespace std;

node *deletenode(node *head, node *del){
    if(head==NULL && del==NULL){
        return head;
    }
    if(head==del){
        head=del->next;
        head->prev=NULL;
        free(del);
        return head;
    }
    if(del->next!=NULL){
        del->next->prev=del->prev;
        del->prev->next=del->next;
        free(del);
        return head;
    }
    if(del->next==NULL){
        del->prev->next=NULL;
        free(del);
        return head;
    }
    return head;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(3);
    dl.insertAtEnd(5);
    dl.insertAtEnd(7);
    dl.insertAtEnd(10);
    dl.head=deletenode(dl.head,dl.head);
    dl.head=deletenode(dl.head,dl.head);
    dl.head=deletenode(dl.head,dl.head);
    dl.print();
    cout<<endl;
    return 0;
}