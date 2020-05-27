#include <iostream>
#include <unordered_set>
#include "ll.h"

using namespace std;

int countNodes(node *curr_ptr){
    node *temp=curr_ptr;
    int count=1;
    temp=temp->next;
    while(temp!=curr_ptr){
        count++;
        temp=temp->next;
    }
    return count;
}

int countLoop(node *head){
    node *slow_ptr=head, *fast_ptr=head;
    while(slow_ptr && fast_ptr && fast_ptr->next!=NULL){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if(slow_ptr==fast_ptr){
            return countNodes(slow_ptr);
        }
    }
    return 0;
}


int main(){
    linkedlist l;
    for(int i=1;i<7;i++){
        l.insertAtEnd(i);
    }
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;//created a loop by self
    cout<<countLoop(l.head);
    // l.print();
    cout<<endl;
    return 0;
}