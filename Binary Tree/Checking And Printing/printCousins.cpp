#include <iostream>
using namespace std;

struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
// A utility function to create a new  
// Binary Tree Node 
Node *newNode(int item) 
{ 
    Node *temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int getLevel(Node *root, Node *node, int level) 
{ 
      
    // base cases 
    if (root == NULL) 
        return 0; 
    if (root == node) 
        return level; 
  
    // If node is present in left subtree 
    int downlevel = getLevel(root->left, 
                             node, level + 1); 
    if (downlevel != 0) 
        return downlevel; 
  
    // If node is not present in left subtree 
    return getLevel(root->right, node, level + 1); 
}

void printGivenLevel(Node* root, Node *node, int level) 
{
    if (root == NULL || level < 2) 
        return;
    
    if (level == 2) 
    { 
        if (root->left == node || root->right == node) 
            return; 
        if (root->left) 
            cout << root->left->data << " "; 
        if (root->right) 
            cout << root->right->data; 
    }

    else if (level > 2) 
    { 
        printGivenLevel(root->left, node, level - 1); 
        printGivenLevel(root->right, node, level - 1); 
    } 
}

void printCousins(Node *root, Node *node) 
{ 
    // Get level of given node 
    int level = getLevel(root, node, 1); 
  
    // Print nodes of given level. 
    printGivenLevel(root, node, level); 
}

int main(){
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    printCousins(root, root->left->right);
    cout<<endl;
    return 0;
}