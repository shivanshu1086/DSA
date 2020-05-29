#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class linkedlist{
public:
    node *head;
    node *tail;

    linkedlist(){
        head=NULL;
        tail=NULL;
    }

    void insertAtEnd(int x){
        if(head==NULL){
            head=new node(x);
            tail=head;
        }
        else{
            node *temp=new node(x);
            tail->next=temp;
            tail=temp;
        }
    }

    void print(){
        node *temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }

    int length(node *head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
};