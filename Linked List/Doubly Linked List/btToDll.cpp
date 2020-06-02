#include <iostream>
#include <queue>
#include <vector>
#include "dll.h"

using namespace std;

void btToDll(node *root, node **head_ref){
    if(root==NULL){
        return;
    }

    btToDll(root->next,head_ref);
    root->next=*head_ref;

    if(*head_ref!=NULL){
        (*head_ref)->prev=root;
    }

    *head_ref=root;

    btToDll(root->prev,head_ref);
}


void printList(node* head) 
{ 
    printf("Extracted Double Linked list is:\n"); 
    while (head) 
    { 
        printf("%d ", head->data); 
        head = head->next; 
    } 
}

int main()
{
    node *root=new node(5);
    root->prev=new node(3);
    root->next=new node(6);
    root->prev->prev=new node(1);
    root->prev->next=new node(4);
    root->next->next=new node(8);
    root->prev->prev->prev=new node(0);
    root->prev->prev->next=new node(2);
    root->next->next->prev=new node(7);
    root->next->next->next=new node(9);

    node *head=NULL;
    btToDll(root,&head);
    printList(head);
    cout<<endl;
    return 0;
}
