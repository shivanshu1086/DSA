#include <iostream>

using namespace std;

class node  
{  
    public: 
int data;  
node *left;  
node *right;  
node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
};
int updatetree(node *root)  
{  
    // Base cases  
    if (!root)  
        return 0;  
    if (root->left == NULL && root->right == NULL)  
        return root->data;  
  
    // Update left and right subtrees  
    int leftsum = updatetree(root->left);  
    int rightsum = updatetree(root->right);  
  
    // Add leftsum to current node  
    root->data += leftsum;  
  
    // Return sum of values under root  
    return root->data + rightsum;  
}  


void printInorder(node* Node)  
{  
    if (Node == NULL)  
        return;  
    printInorder(Node->left);  
    cout<<" "<<Node->data;  
    printInorder(Node->right);  
}  


int main(){
     struct node *root = new node(1);  
    root->left     = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);  
    root->right->right = new node(6);  
  
    updatetree(root);  
  
    cout << "Inorder traversal of the modified tree is: \n";  
    printInorder(root); 
    cout<<endl;
    return 0;
}