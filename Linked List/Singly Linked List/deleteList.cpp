#include <iostream>
#include "ll.h"

using namespace std;

node *deletell(node *head){
    node *first=head;
    node *second;
    while(first!=NULL){
        second=first->next;
        free(first);
        first=second;
    }
    return first;
}

int main(){
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtEnd(i);
    }
    l.print();
    l.head=deletell(l.head);
    l.print();
    cout<<endl;
    return 0;
}