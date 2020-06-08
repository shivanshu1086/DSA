#include <iostream>
#include <stack>
#include <climits>

#define MAX 1000
using namespace std;

class node{
public:
    node *prev;
    int data;
    node *next;
};

class Stack{
public:
    node *head;
    node *mid;
    int count;
};

Stack *createStack(){
    Stack *ms = new Stack();
    ms->count=0;
    return ms;
}

void push(Stack *ms, int x){
    //create a node and add it to ms
    node *newNode = new node();
    newNode->data = x;

    newNode->prev=NULL;
    newNode->next=ms->head;

    ms->count+=1;
    if(ms->count==1){
        ms->mid=newNode;
    }
    else{
        ms->head->prev=newNode;
        if(!(ms->count & 1))
        ms->mid=ms->mid->prev;
    }
    ms->head=newNode;
}

int pop(Stack *ms){
    if(ms->count==0){
        cout<<"Stack is empty";
        return -1;
    }
    node *head=ms->head;
    int item=head->data;
    ms->head=head->next;
    if(ms->head!=NULL){
        ms->head->prev=NULL;
    }
    ms->count-=1;

    if((ms->count)&1){
        ms->mid=ms->mid->next;
    }
    free(head);
    return item;
}

int findmid(Stack *ms){
    if(ms->count==0){
        cout<<"Stack is empty";
        return -1;
    }
    return ms->mid->data;
}

int main() 
{
    Stack *ms=createStack();
    push(ms,11);
    push(ms,12);
    push(ms,13);
    push(ms,14);
    push(ms,15);
    push(ms,16);
    push(ms,17);

    cout<<"item is popped "<<pop(ms)<<endl;
    cout<<"item is popped "<<pop(ms)<<endl;
    cout<<"Middle element is "<<findmid(ms)<<endl;
    cout<<endl;
	return 0; 
} 
