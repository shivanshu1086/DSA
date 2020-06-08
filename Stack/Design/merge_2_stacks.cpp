#include <iostream>
#include <stack>
#include <climits>

#define MAX 1000
using namespace std;

class node{
public:
    int data;
    node *next;
};

class myStack{
public:
    node *head;
    node *tail;

    myStack(){
        head=NULL;
        tail=NULL;
    }
};

myStack *create(){
    myStack *ms=new myStack();
    return ms;
}

void push(int x, myStack *ms){
    node *temp=new node();
    temp->data=x;
    temp->next=ms->head;

    if(ms->head==NULL){
        ms->tail=temp;
    }
    ms->head=temp;
}

int pop(myStack *ms){
    if(ms->head==NULL){
        cout<<"Stack is empty";
        return INT_MAX;
    }
    else{
        node *temp=ms->head;
        ms->head=ms->head->next;
        int popped = temp->data;
        delete temp;
        return popped;
    }
}

void merge(myStack *ms1, myStack *ms2){
    if(ms1->head==NULL){
        ms1->head=ms2->head;
        ms1->tail=ms2->tail;
        return;
    }
    ms1->tail->next=ms2->head;
    ms1->tail=ms2->tail;
}

void display(myStack* ms) 
{ 
    node* temp = ms->head; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    }
} 

int main() 
{
    myStack* ms1 = create(); 
    myStack* ms2 = create(); 
  
    push(6, ms1); 
    push(5, ms1); 
    push(4, ms1); 
    push(9, ms2); 
    push(8, ms2); 
    push(7, ms2); 
    merge(ms1, ms2); 
    display(ms1);
    cout<<endl;
	return 0; 
} 
