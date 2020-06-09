#include <iostream>
#include <queue>
#include <climits>

#define MAX 1000
using namespace std;

class node{
public:
    int value;
    node *next;
    node *prev;
};

class dequeue{
    node *head;
    node *tail;

public:
    dequeue(){
        head=tail=NULL;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    int size(){
        if(!isEmpty()){
            node *temp=head;
            int len=0;
            while(temp!=NULL){
                len++;
                temp=temp->next;
            }
            return len;
        }
        return 0;
    }

    void insert_first(int x){
        node *temp=new node[sizeof(node)];
        temp->value=x;

        if(head==NULL){
            head=tail=temp;
            temp->next=temp->prev=NULL;
        }
        else{
            head->prev=temp;
            temp->next=head;
            temp->prev=NULL;
            head=temp;
        }
    }

    void insert_last(int x){
        node *temp=new node[sizeof(node)];
        temp->value=x;

        if(head==NULL){
            head=tail=temp;
            temp->next=temp->prev=NULL;
        }
        else{
            tail->next=temp;
            temp->next=NULL;
            temp->prev=tail;
            tail=temp;
        }
    }

    void remove_first(){
        if(!(isEmpty())){
            node *temp=head;
            head=head->next;
            head->prev=NULL;
            free(temp);
            return;
        }
        cout<<"List is empty"<<endl;
    }

    void remove_last(){
        if(!(isEmpty())){
            node *temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            free(temp);
            return;
        }
        cout<<"List is empty"<<endl;
    }

    void display(){
        if(!(isEmpty())){
            node *temp=head;
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<endl;
            return;
        }
        cout<<"List is empty"<<endl;
    }
};

class Stack:public dequeue{//inheritence
public:
    void push(int x){
        insert_last(x);
    }

    void pop(){
        remove_last();
    }
};

class Queue: public dequeue{//inheritence
public:
    void enqueue(int x){
        insert_last(x);
    }

    void dqueue(){
        remove_first();
    }
};


int main() 
{
    Stack stk; 
  
    // push 7 and 8 at top of stack 
    stk.push(7); 
    stk.push(8); 
    cout << "Stack: "; 
    stk.display(); 
  
    // pop an element 
    stk.pop(); 
    cout << "Stack: "; 
    stk.display(); 
  
    // object of Queue 
    Queue que; 
  
    // insert 12 and 13 in queue 
    que.enqueue(12); 
    que.enqueue(13); 
    cout << "Queue: "; 
    que.display(); 
  
    // delete an element from queue 
    que.dqueue(); 
    cout << "Queue: "; 
    que.display(); 
  
    cout << "Size of Stack is " << stk.size() << endl; 
    cout << "Size of Queue is " << que.size() << endl;
    cout<<endl;
	return 0; 
} 
