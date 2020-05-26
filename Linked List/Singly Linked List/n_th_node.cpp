#include <iostream>
#include "ll.h"

using namespace std;

int n_th_node(node *head, int key){
    node *temp=head;
    int n=0;
    while(n<key-1){
        n++;
        temp=temp->next;
    }
    return temp->next->data;
}

int main(){
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtEnd(i);
    }
    cout<<n_th_node(l.head,3);
    // l.print();
    cout<<endl;
    return 0;
}