#include <iostream>

using namespace std;

class node  
{  
    public: 
    int data;  
    node *left, *right;  
};  
  
// function to allocate new node with given data  
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return (Node);  
} 

int treePathsSumUtil(node *root, int val)  
{  
    // Base case  
    if (root == NULL) return 0;  
  
    // Update val  
    val = (val*10 + root->data);  
  
    // if current node is leaf, return the current value of val  
    if (root->left==NULL && root->right==NULL)  
    return val;  
  
    // recur sum of values for left and right subtree  
    return treePathsSumUtil(root->left, val) +  
        treePathsSumUtil(root->right, val);  
}

int treePathsSum(node *root)  
{  
    // Pass the initial value as 0 
    // as there is nothing above root  
    return treePathsSumUtil(root, 0);  
}

int main(){
    node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  
    cout<<"Sum of all paths is "<<treePathsSum(root); 
    cout<<endl;
    return 0;
}