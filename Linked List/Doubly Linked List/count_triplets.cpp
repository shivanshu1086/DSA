#include <iostream>
#include "dll.h"
using namespace std;

int countPairs(node *first, node *second, int value){
    int count=0;

    while(first!=NULL && second!=NULL && first!=second && second->next!=first){
        if((first->data+second->data)==value){
            
            count++;
            first=first->next;
            second=second->prev;
        }
        else if((first->data+second->data)>value){
            second=second->prev;
        }
        else{
            first=first->next;
        }
    }
    return count;
}

void count_triplets(node *head, int x){
    if(head==NULL){
        return;
    }
    int count=0;
    node *first,*current,*last;
    last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    for(current=head;current!=NULL;current=current->next){
        first=current->next;
        count+=countPairs(first,last,x-current->data);
    }
    cout<<count;
}

int main(){
    dlinkedlist dl;
    dl.insertAtEnd(1);
    dl.insertAtEnd(2);
    dl.insertAtEnd(4);
    dl.insertAtEnd(5);
    dl.insertAtEnd(6);
    dl.insertAtEnd(8);
    dl.insertAtEnd(9);
    count_triplets(dl.head,17);
    dl.print();
    cout<<endl;
    return 0;
}