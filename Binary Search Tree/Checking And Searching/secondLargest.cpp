#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
  
// helper function to create a new Node 
Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->right = temp->left = NULL; 
    return temp; 
}

void secondLargestUtil(Node *root, int *k){
    if(root==NULL){
        return;
    }

    secondLargestUtil(root->right,k);
    if(--(*k)==0){
        cout<<root->data;
        return;
    }
    secondLargestUtil(root->left,k);
}

void secondLargest(Node *root){
    int k=2;
    secondLargestUtil(root,&k);
}

int main(){
    Node* root = newNode(50); 
    root->left = newNode(30); 
    root->right = newNode(70); 
    root->left->left = newNode(20); 
    root->left->right = newNode(40); 
    root->right->left = newNode(60); 
    root->right->right = newNode(80); 
  
    secondLargest(root);
    cout<<endl;
    return 0;
}