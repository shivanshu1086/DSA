#include <iostream>
#include <queue>

using namespace std;


class Node{
public:
    int data;
    int priority;
    Node *next;
};

Node *createNew(int data, int priority){
    Node *temp = new Node();
    temp->data=data;
    temp->priority=priority;
    temp->next=NULL;
    return temp;
}

void push(Node **head, int data, int priority){
    Node *start=*head;
    Node *temp = createNew(data,priority);

    if((*head)->priority>priority){
        temp->next=*head;
        *(head)=temp;
    }
    else{
        while(start->next!=NULL && start->next->priority<priority){
            start=start->next;
        }
        temp->next=start->next;
        start->next=temp;
    }
}

bool isEmpty(Node **head){
    return *(head)==NULL;
}

int peek(Node **head){
    return (*head)->data;
}

void pop(Node **head){
    Node *temp=*head;
    (*head)=(*head)->next;
    free(temp);
}

int main(){
    Node *pq = createNew(4,1);
    push(&pq,5,2);
    push(&pq,6,3);
    push(&pq,7,0);

    while(!isEmpty(&pq)){
        cout<<" "<<peek(&pq);
        pop(&pq);
    }
    cout<<endl;
	return 0;
}