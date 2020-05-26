#include <iostream>
#include "ll.h"

using namespace std;

int length(node *head){
    //iterative way
    /*node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;*/

    
    //recursive way
    if(head==NULL){
        return 0;
    }
    return 1+length(head->next);
}

int main(){
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtEnd(i);
    }
    cout<<"Length of the linked list is: "<<length(l.head)<<endl;
    l.print();
    cout<<endl;
    return 0;
}