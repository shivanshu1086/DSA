#include <iostream>

using namespace std;

//reverse a stack using linkedlist without using extra space

class node{
public:
    int data;
    node *next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class Stack{
public:
    node *top;

    Stack(){
        top=NULL;
    }

    void push(int x){
        if(top==NULL){
            top=new node(x);
        }
        else{
            node *temp=new node(x);
            temp->next=top;
            top=temp;
        }
    }

    void display(){
        node *temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void reverse(){
        node *prev;
        prev=NULL;
        node *curr=top;
        node *next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        top=prev;
    }

    int top_ele(){
        return top->data;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Original Stack" << endl;
    s.display();
    s.reverse();
    cout<<endl << "Reversed Stack" << endl;
    s.display();
    cout<<endl;
    cout<<s.top_ele();
    cout<<endl;
    return 0;
}