#include <iostream>

using namespace std;

struct Node { 
    int data; 
    Node* left, *right; 
};

struct Node* newNode(int data) 
{ 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
}

void printFullNodes(Node *root){
    if(root==NULL){
        return;
    }

    if((root->left) && (root->right)){
        cout<<root->data<<" ";
    }

    printFullNodes(root->left);
    printFullNodes(root->right);
}

int main(){
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->right = newNode(7); 
    root->right->right->right = newNode(8); 
    root->right->left->right->left = newNode(9); 
    printFullNodes(root);
    cout<<endl;
    return 0;
}