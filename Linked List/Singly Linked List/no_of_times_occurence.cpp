#include <iostream>
#include "ll.h"

using namespace std;

int no_of_times_occurence(node *head, int ele){
    // node *temp=head;
    // int cnt=0;
    // while(temp!=NULL){
    //     if(temp->data==ele){
    //         cnt++;
    //         temp=temp->next;
    //     }
    //     else{
    //         temp=temp->next;
    //     }
    // }
    // return cnt;//iteration

    //recursive way
    if(head==NULL){
        return 0;
    }
    else{
        if(head->data==ele){
            return 1+no_of_times_occurence(head->next,ele);
        }
        else{
            return no_of_times_occurence(head->next,ele);
        }
    }
}

int main(){
    linkedlist l;
    // for(int i=1;i<7;i++){
    //     l.insertAtEnd(i);
    // }
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(1);
    l.insertAtEnd(3);
    l.insertAtEnd(1);
    cout<<no_of_times_occurence(l.head,1)<<endl;
    l.print();
    cout<<endl;
    return 0;
}