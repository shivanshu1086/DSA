#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp=new node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

int findADepth(node *node) 
{ 
   int d = 0; 
   while (node != NULL) 
   { 
      d++; 
      node = node->left; 
   } 
   return d; 
}

bool isPerfectRec(node* root, int d, int level = 0) 
{ 
    // An empty tree is perfect 
    if (root == NULL) 
        return true; 
  
    // If leaf node, then its depth must be same as 
    // depth of all other leaves. 
    if (root->left == NULL && root->right == NULL) 
        return (d == level+1); 
  
    // If internal node and one child is empty 
    if (root->left == NULL || root->right == NULL) 
        return false; 
  
    // Left and right subtrees must be perfect. 
    return isPerfectRec(root->left, d, level+1) && 
           isPerfectRec(root->right, d, level+1); 
}

bool isPerfect(node *root) 
{ 
   int d = findADepth(root); 
   return isPerfectRec(root, d); 
}

int main(){
    node *root = newNode(10);
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        printf("Yes\n"); 
    else
        printf("No\n");
    cout<<endl;
    return 0;
}