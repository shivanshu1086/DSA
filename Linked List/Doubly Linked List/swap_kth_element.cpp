#include <iostream>
#include "dll.h"
using namespace std;

int countNodes(node *s)
{ 
    int count = 0; 
    while (s != NULL) 
    { 
        count++; 
        s = s->next; 
    } 
    return count;
}

node *swap_kth_element(node *head, int k){
    int n=countNodes(head);
    if(n<k) return head;

    if(2*k-1==n) return head;

    node *x=head;
    node *x_prev=NULL;
    for(int i=1;i<k;i++){
        x_prev=x;
        x=x->next;
    }

    node *y=head;
    node *y_prev=NULL;
    for(int i=1;i<n-k+1;i++){
        y_prev=y;
        y=y->next;
    }

    if(x_prev){
        x_prev->next=y;
    }

    if(y_prev){
        y_prev->next=x;
    }

    node *temp=x->next;
    x->next=y->next;
    y->next=temp;

    if(k==1){
        head=y;
    }
    if(k==n){
        head=x;
    }
    return head;
}


int main(){
    dlinkedlist dl;
    for(int i=1;i<=8;i++){
        dl.insertAtEnd(i);
    }
    dl.head=swap_kth_element(dl.head,3);
    // dl.head=swap_kth_element(dl.head,3);
    dl.print();
    cout<<endl;
    return 0;
}