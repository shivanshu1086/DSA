#include <iostream>
#include <stack>
#include <string>
#include "ll.h"

using namespace std;

int Josephus_Circle(node *head, int n, int m){
    node *ptr1=head, *ptr2=head;
    while(ptr1->next!=ptr1){
        int count=1;
        while(count!=m){
            ptr2=ptr1;
            ptr1=ptr1->next;
            count++;
        }

        ptr2->next=ptr1->next;
        free(ptr1);
        ptr1=ptr2->next;
    }
    return ptr1->data;
}

int main(){
    linkedlist l;
    int n=14,m=2;
    for(int i=1;i<=n;i++){
        l.insertAtEnd(i);
    }
    node *temp=l.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l.head;
    cout<<Josephus_Circle(l.head,m,n);
    // l.print();
    cout<<endl;
    return 0;
}