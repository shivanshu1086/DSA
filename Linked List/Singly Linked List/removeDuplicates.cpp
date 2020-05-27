#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *removeDuplicates(node *head){
    node *curr=head;
    node *next;

    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            next=curr->next->next;
            free(curr->next);
            curr->next=next;
        }
        else{
            curr=curr->next;
        }
    }

    return head;
}

int main(){
    linkedlist l;
    // for(int i=1;i<7;i++){
    //     l.insertAtEnd(i);
    // }
    l.insertAtEnd(11);
    l.insertAtEnd(11);
    l.insertAtEnd(11);
    l.insertAtEnd(21);
    l.insertAtEnd(43);
    l.insertAtEnd(43);
    l.insertAtEnd(60);
    l.print();
    cout<<endl;
    l.head=removeDuplicates(l.head);//numbers are sorted
    l.print();
    cout<<endl;
    return 0;
}