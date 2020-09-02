#include <iostream>
#include <queue>

using namespace std;

class Node  
{  
    public: 
    int data;  
    Node *left;  
    Node *right;  
};  

Node * newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  

void printPreorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    cout << root->data << " "; 
    printPreorder(root->left);
    printPreorder(root->right); 
}

void newNOde(int data, Node **head) 
{  
    if(head==NULL){
        (*head) = new Node();
        (*head)->data = data;
        (*head)->left = (*head)->right = NULL;
    }
    else{
        Node *temp = new Node();
        temp->data = data;
        temp->left = NULL;
        temp->right=(*head);
        (*head) = temp;
    }
}  

void BSTToSortedLL(Node *root, Node **head){
    if(root==NULL){
        return;
    }
    BSTToSortedLL(root->right,head);
    newNOde(root->data, head);
    BSTToSortedLL(root->left,head);
}

void SortedLLToMinHeap(Node *&root, Node *&head){
    if(head==NULL){
        return;
    }

    queue<Node *> q;
    root = head;
    head=head->right;
    root->right = NULL;
    q.push(root);

    while(head!=NULL){
        Node *parent = q.front();
        q.pop();

        Node *left = head;
        head= head->right;
        left->right = NULL;
        q.push(left);

        parent->left = left;

        if(head){
            Node *right = head;
            head=head->right;
            right->right=NULL;
            q.push(right);

            parent->right = right;
        }
    }
}

void BSTToMinHeap(Node* &root) 
{
    Node *head = NULL;

    BSTToSortedLL(root, &head);
    
    root = NULL;
    SortedLLToMinHeap(root, head);
}

int main(){
    Node* root = newNode(8); 
    root->left = newNode(4); 
    root->right = newNode(12); 
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
    root->left->left = newNode(2); 
    root->left->right = newNode(6);

    BSTToMinHeap(root);

    printPreorder(root);
    cout<<endl;
    return 0;
}