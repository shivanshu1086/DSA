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

void transformTreeUtil(Node *root, int *sum){
    if (root == NULL)  return;

    transformTreeUtil(root->right, sum);

    *sum = *sum + root->data;

    root->data = *sum - root->data;

    transformTreeUtil(root->left,sum);
}

void transformTree(Node *root){
    int sum = 0;
    transformTreeUtil(root, &sum);
}

int main(){
    struct Node *root = newNode(11); 
    root->left = newNode(2); 
    root->right = newNode(29); 
    root->left->left = newNode(1); 
    root->left->right = newNode(7); 
    root->right->left = newNode(15); 
    root->right->right = newNode(40); 
    root->right->right->left = newNode(35); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    transformTree(root); 
  
    cout << "\n\nInorder Traversal of transformed tree\n"; 
    printInorder(root);
    cout<<endl;
    return 0;
}