#include <iostream>
using namespace std;

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
}; 

void printArray(int [], int);  
void printPathsRecur(node*, int [], int);  
node* newNode(int );  
void printPaths(node*);

node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  
  
/* Utility that prints out an array on a line */
void printArray(int ints[], int len)  
{  
    int i;  
    for (i = 0; i < len; i++) 
    {  
        cout << ints[i] << " ";  
    }  
    cout << endl;  
}

void printPaths(node* node)  
{  
    int path[1000];  
    printPathsRecur(node, path, 0);  
}
void printPathsRecur(node* node, int path[], int pathLen)  
{  
    if (node == NULL) return;  
      
    /* append this node to the path array */
    path[pathLen] = node->data;  
    pathLen++;  
      
    /* it's a leaf, so print the path that led to here */
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
    /* otherwise try both subtrees */
        printPathsRecur(node->left, path, pathLen);  
        printPathsRecur(node->right, path, pathLen);  
    }  
}

int main(){
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    /* Print all root-to-leaf  
    paths of the input tree */
    printPaths(root);
    cout<<endl;
    return 0;
}