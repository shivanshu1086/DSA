#include <iostream>
#include <queue>
#include <vector>
#include "dll.h"

using namespace std;


class compare{
public:
    bool operator()(node *p1, node *p2){
        return p1->data>p2->data;
    }
};


node *sortAKsorted(node *head, int k){
    if(head==NULL){
        return head;
    }

    priority_queue<node *, vector<node*>,compare> pq;

    node *newHead=NULL;
    node *last;

    for(int i=0;head!=NULL&&i<=k;i++){
        pq.push(head);
        head=head->next;
    }

    while(!pq.empty()){
        if(newHead==NULL){
            newHead=pq.top();
            newHead->prev=NULL;
            last=newHead;
        }

        else{
            last->next=pq.top();
            pq.top()->prev=last;
            last=pq.top();
        }

        pq.pop();
        if(head!=NULL){
            pq.push(head);
            head=head->next;
        }
    }

    last->next=NULL;
    return newHead;
}


int main()
{
    dlinkedlist dl;
    dl.insertAtEnd(3);
    dl.insertAtEnd(6);
    dl.insertAtEnd(2);
    dl.insertAtEnd(12);
    dl.insertAtEnd(56);
    dl.insertAtEnd(8);
    int k=2;
    dl.print();
    cout<<endl<<endl;
    dl.head=sortAKsorted(dl.head,k);
    dl.print();
    cout<<endl;
    return 0;
}
