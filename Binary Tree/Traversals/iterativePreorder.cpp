#include <iostream>
#include <stack>
using namespace std;

struct node 
{ 
    char data; 
    struct node* left; 
    struct node* right; 
};

node* newNode(int data) 
{ 
    node* temp = new node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return (temp); 
}

void iterativePreorder(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
       return; 
  
    // Create an empty stack and push root to it 
    stack<node *> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) 
    { 
        // Pop the top item from stack and print it 
        struct node *node = nodeStack.top(); 
        printf ("%c ", node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 
}

int main(){
    struct node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o');

    iterativePreorder(root);
    cout<<endl;
    return 0;
}