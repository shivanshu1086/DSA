#include <iostream>
#include <cmath>

using namespace std;

class node{
public:
    int data;
    node *next;
};

void print(node* head)  
{  
    while (head != NULL)  
    {  
        cout << head->data << " ";  
        head = head->next;  
    }  
    cout<<endl;  
} 

void push(node** head_ref, int new_data)  
{  
    // allocate node  
    node* new_node = new node(); 
      
    // put in the data  
    new_node->data = new_data;  
      
    // link the old list off the new node  
    new_node->next = (*head_ref);  
      
    // move the head to point to the new node  
    (*head_ref) = new_node;  
}

int printsqrtn(node *head){
    if(head==NULL){
        return -1;
    }

    int length=0;
    node *temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    int pos=floor(sqrt(length));
    // cout<<pos;
    if(pos==0){
        return head->data;
    }

    temp=head;
    int cnt=0;

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    return temp->data;
}

int main(){
    node *head=NULL;
    push(&head, 90);  
    push(&head, 80);  
    push(&head, 70);  
    push(&head, 60);  
    push(&head, 50);  
    push(&head, 40);  
    push(&head, 30);  
    push(&head, 20);  
    push(&head, 10);
    print(head);
    cout<<endl<<endl;
    cout << "sqrt(n)th node is " << printsqrtn(head);
    cout<<endl;
    return 0;
}