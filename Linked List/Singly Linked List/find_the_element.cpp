#include <iostream>
#include "ll.h"

using namespace std;

// bool findele(node *head, int x){
//     if(head==NULL){
//         return false;
//     }
//     else if(head->data==x){
//         return true;
//     }
//     else{
//         return findele(head->next,x);
//     }
// }//recursive way

bool findele(node *head, int x){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}

int main(){
    linkedlist l;
    for(int i=1;i<10;i++){
        l.insertAtEnd(i);
    }
    cout<<boolalpha<<findele(l.head,5);
    // l.print();
    cout<<endl;
    return 0;
}