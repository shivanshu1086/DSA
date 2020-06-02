#include <iostream>
#include <unordered_set>
#include "dll.h"
//unsorted
using namespace std;

void deletenode(node *head, node *del){
    if(head==NULL || del==NULL){
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

void remove_duplicates(node *head){
    if(head==NULL || head->next==NULL){
        return;
    }

    unordered_set<int> s;
    node *curr=head;
    node *next;

    while(curr!=NULL){
        if(s.find(curr->data)!=s.end()){
            next=curr->next;
            deletenode(head,curr);
            curr=next;
        }
        else{
            s.insert(curr->data);
            curr=curr->next;
        }
    }
}

int main()
{
    dlinkedlist dl;
    dl.insertAtEnd(12);
    dl.insertAtEnd(12);
    dl.insertAtEnd(10);
    dl.insertAtEnd(4);
    dl.insertAtEnd(8);
    dl.insertAtEnd(4);
    dl.insertAtEnd(6);
    dl.insertAtEnd(4);
    dl.insertAtEnd(4);
    dl.insertAtEnd(8);
    dl.print();
    cout<<endl<<endl;
    remove_duplicates(dl.head);
    dl.print();
    cout<<endl;
    return 0;
}
