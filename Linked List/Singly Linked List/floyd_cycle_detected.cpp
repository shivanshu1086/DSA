#include <iostream>
#include <unordered_set>
#include "ll.h"

using namespace std;

bool detectLoop(node *head){
    unordered_set<node*> s;
    node *temp=head;
    while(temp!=NULL){
        if(s.find(temp)!=s.end()){
            return true;
        }
        s.insert(temp);
        temp=temp->next;
    }
    return false;
}//one way

//another way (Floyd Cycle-Finding algorithm)

bool floyd_cycle_detected(node *head){
    node *slow_ptr=head;
    node *fast_ptr=head;

    while(slow_ptr&&fast_ptr&&fast_ptr->next){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if(slow_ptr==fast_ptr){
            return true;
        }
    }
    return false;
}//fastest way

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
    // cout<<boolalpha<<detectLoop(l.head);
    cout<<boolalpha<<floyd_cycle_detected(l.head);
    // l.print();
    cout<<endl;
    return 0;
}