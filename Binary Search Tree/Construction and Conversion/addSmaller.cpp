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

void addSmallerUtil(Node *root, int *sum){
    if(root==NULL){
        return;
    }

    addSmallerUtil(root->left,sum);

    (*sum) = (*sum) + root->data;

    root->data = *sum;

    addSmallerUtil(root->right,sum);
}

void addSmaller(Node *root){
    int sum = 0;
    addSmallerUtil(root, &sum);
}

int main(){
    Node* root = newNode(9); 
    root->left = newNode(6); 
    root->right = newNode(15);

    printf(" Original BST\n"); 
    printInorder(root); 
  
    addSmaller(root); 
  
    printf("\n BST To Binary Tree\n"); 
    printInorder(root);

    cout<<endl;
    return 0;
}