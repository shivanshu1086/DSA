#include <iostream>
#include "ll.h"

using namespace std;

int midele(node *head){
    node *fastptr=head;
    node *slowptr=head;

    while(fastptr!=NULL && fastptr->next!=NULL){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    return slowptr->data;
}

int main(){
    linkedlist l;
    for(int i=1;i<7;i++){
        l.insertAtEnd(i);
    }
    cout<<midele(l.head)<<endl;
    l.print();
    cout<<endl;
    return 0;
}