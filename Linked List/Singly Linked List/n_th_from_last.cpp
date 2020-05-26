#include <iostream>
#include "ll.h"

using namespace std;

int n_th_from_last(node *head, int key){
    node *main_ptr=head;
    node *ref_ptr=head;
    int count=0;
    while(count!=key){
        ref_ptr=ref_ptr->next;
        count++;
    }
    while(ref_ptr!=NULL){
        ref_ptr=ref_ptr->next;
        main_ptr=main_ptr->next;
    }
    return main_ptr->data;
}//or we can use (length-key) and iterate till that length and print the data

int main(){
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtEnd(i);
    }
    cout<<n_th_from_last(l.head,6)<<" is 6th from the last"<<endl;
    l.print();
    cout<<endl;
    return 0;
}