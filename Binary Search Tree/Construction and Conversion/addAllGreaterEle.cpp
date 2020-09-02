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

void addGreaterUtil(Node *root, int *sum){
    if(root==NULL){
        return;
    }

    addGreaterUtil(root->right,sum);
    (*sum) = (*sum) + root->data;

    root->data = *sum;

    addGreaterUtil(root->left,sum);
}

void addGreater(Node *root){
    int sum=0;
    addGreaterUtil(root, &sum);
}

int main(){
    Node *root = newNode(5);  
    root->left = newNode(2);  
    root->right = newNode(13);  
  
    cout << "Inorder traversal of the " 
         << "given tree" << endl;  
    printInorder(root);  
  
    addGreater(root);
    cout << endl; 
    cout << "Inorder traversal of the " 
         << "modified tree" << endl;  
    printInorder(root);
    cout<<endl;
    return 0;
}