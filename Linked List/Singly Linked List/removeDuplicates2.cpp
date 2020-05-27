#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

node *removeDuplicates(node *head){
    node *curr=head;
    node *next,*prev;

    while(curr!=NULL && curr->next!=NULL){
        prev=curr;
        while(prev->next!=NULL){
            if(prev->next->data==curr->data){
                next=prev->next;
                prev->next=prev->next->next;
                delete(next);
            }
            else{
                prev=prev->next;
            }
        }
        curr=curr->next;
    }

    return head;
}

int main(){
    linkedlist l;
    // for(int i=1;i<7;i++){
    //     l.insertAtEnd(i);
    // }
    l.insertAtEnd(12);
    l.insertAtEnd(11);
    l.insertAtEnd(12);
    l.insertAtEnd(21);
    l.insertAtEnd(41);
    l.insertAtEnd(43);
    l.insertAtEnd(21);
    l.print();
    cout<<endl;
    l.head=removeDuplicates(l.head);//unsorted numbers
    l.print();
    cout<<endl;
    return 0;
}