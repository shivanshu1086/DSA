#include <iostream>

using namespace std;

class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
};  

class LNode  
{  
    public: 
    int data;  
    LNode* next;  
};

void push(LNode** head_ref, int new_data)  
{  
    /* allocate node */
    LNode* new_node = new LNode(); 
      
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}
  
// A utility function to create a node  
node* newNode (int data)  
{  
    node* temp = new node(); 
  
    temp->data = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}

void printList(LNode *node)  
{  
    while(node!=NULL)  
    {  
        cout << node->data << " ";  
        node = node->next;  
    }  
}  
void preOrder(node* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 

int coutnNode(LNode *head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

node *sortedListToBSTRecur(LNode **head, int n){
    if(n<=0){
        return NULL;
    }

    node *left = sortedListToBSTRecur(head, n/2);

    node *root = newNode((*head)->data);
    root->left = left;

    (*head) = (*head)->next;

    root->right = sortedListToBSTRecur(head, n-n/2-1);

    return root;
}

node* sortedListToBST(LNode *head)  
{
    int n =coutnNode(head);

    return sortedListToBSTRecur(&head, n);
}

int main(){
    LNode* head = NULL;  
  
    /* Let us create a sorted linked list to test the functions  
    Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);  
  
    cout<<"Given Linked List ";  
    printList(head);

    node *root = sortedListToBST(head);
    cout<<"\nPreOrder Traversal of constructed BST ";  
    preOrder(root);
    cout<<endl;
    return 0;
}