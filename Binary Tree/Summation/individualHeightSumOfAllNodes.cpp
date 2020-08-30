#include <iostream>
#include <vector>
using namespace std;

struct Node 
{ 
    int data; 
    Node *left,*right; 
};


struct Node* newNode(int data) 
{ 
    struct Node* Node = (struct Node*) 
        malloc(sizeof(struct Node)); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
  
    return (Node); 
}

int getHeight(struct Node* Node) 
{ 
    if (Node == NULL) 
        return 0; 
    else { 
        /* compute the height of each subtree */
        int lHeight = getHeight(Node->left); 
        int rHeight = getHeight(Node->right); 
  
        /* use the larger one */
        if (lHeight > rHeight) 
            return (lHeight + 1); 
        else
            return (rHeight + 1); 
    } 
}

int getTotalHeight(struct Node* root) 
{ 
    if (root == NULL) 
        return 0; 
  
    return getTotalHeight(root->left) +  
           getHeight(root) +  
           getTotalHeight(root->right); 
} 

int main(){
    struct Node* root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    printf("Sum of heights of all Nodes = %d",     
                        getTotalHeight(root));
    cout<<endl;
    return 0;
}