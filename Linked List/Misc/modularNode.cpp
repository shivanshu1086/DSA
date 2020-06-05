#include <iostream>
#include <cmath>

using namespace std;

struct Node { 
    int data; 
    Node* next; 
}; 
  
/* Function to create a new node with given data */
Node* newNode(int data) 
{ 
    Node* new_node = new Node; 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 


Node *modularNode(Node *head, int k){
    if(k<=0||head==NULL){
        return NULL;
    }

    int i=1;
    Node *modularNode=NULL;
    for(Node *temp=head;temp!=NULL;temp=temp->next){
        if(i%k==0){
            modularNode=temp;
        }
        i++;
    }
    return modularNode;
}

int main(){
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
    int k = 2; 
    Node* answer = modularNode(head, k);
    printf("\nModular node is "); 
    if (answer != NULL)  
        printf("%d\n", answer->data); 
    else
        printf("null\n"); 
    cout<<endl;
    return 0;
}