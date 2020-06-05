#include <iostream>
#include <climits>

using namespace std;


struct Node { 
    int data; 
    struct Node* next; 
};

void push(struct Node** head, int data) 
{ 
    // Allocate dynamic memory for newNode. 
    struct Node* newNode =  
         (struct Node*)malloc(sizeof(struct Node)); 
  
    // Assign the data into newNode. 
    newNode->data = data; 
  
    // newNode->next assign the address of 
    // head node. 
    newNode->next = (*head); 
  
    // newNode become the headNode. 
    (*head) = newNode; 
} 
void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        printf("%d -> ", head->data); 
        head = head->next; 
    } 
    cout << "NULL" << endl; 
}

void max_min(Node *head){
    Node *temp=head;

    int mini=INT_MAX;
    int maxi=INT_MIN;

    while(temp!=NULL){
        if(temp->data>maxi){
            maxi=temp->data;
        }
        if(temp->data<mini){
            mini=temp->data;
        }
        temp=temp->next;
    }
    cout<<endl<<maxi<<" "<<mini;
}


int main(){
    // Start with empty list 
    struct Node* head = NULL; 
  
    // Using push() function to construct 
    // singly linked list 
    // 17->22->13->14->15 
    push(&head, 15); 
    push(&head, 14); 
    push(&head, 13); 
    push(&head, 22); 
    push(&head, 17); 
    cout << "Linked list is : " << endl; 
  
    // Call printList() function to display 
    // the linked list. 
    printList(head); 
    // cout << "Maximum element in linked list:"; 
  
    // // Call largestElement() function to get largest 
    // // element in linked list. 
    // cout << largestElement(head) << endl; 
    // cout << "Minimum element in linked list:"; 
  
    // // Call smallestElement() function to get smallest 
    // // element in linked list. 
    // cout << smallestElement(head) << endl; 
    max_min(head);
    cout<<endl;
    return 0;
}
