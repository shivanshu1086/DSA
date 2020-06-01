#include <iostream>

using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;

    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

class dlinkedlist{
public:
    node *head;

    dlinkedlist(){
        head=NULL;
    }

    void insertAtEnd(int x){
        if(head==NULL){
            head=new node(x);
        }
        else{
            node *temp=new node(x);
            node *traverse=head;
            while(traverse->next!=NULL){
                traverse=traverse->next;
            }
            traverse->next=temp;
            temp->prev=traverse;
        }
    }

    void print(){
        node *temp=head;
        node *temp2=NULL;
        cout<<"Forward Traverse: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp2=temp;
            temp=temp->next;
        }
        cout<<endl<<"Backward Traverse: ";
        while(temp2!=NULL){
            cout<<temp2->data<<" ";
            temp2=temp2->prev;
        }
    }
};

