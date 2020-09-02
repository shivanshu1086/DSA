#include <iostream>

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

void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    
    printInorder(root->left);
    cout << root->data << " "; 
    printInorder(root->right); 
}

int minEleOfTree(Node *root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int main(){
    Node* root = newNode(8); 
    root->left = newNode(4); 
    root->right = newNode(12); 
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
    root->left->left = newNode(2); 
    root->left->right = newNode(6);

    cout<<"Min element is "<<minEleOfTree(root);
    cout<<endl;
    return 0;
}