#include <iostream>

using namespace std;

struct Node  
{
    int data;  
    Node* left;  
    Node* right;
};
struct Node* newNode(int key) 
{ 
    struct Node* node = new Node; 
    node->data= key; 
    node->left = node->right = NULL; 
    return node; 
} 

void convertTree(Node *root){
    if(root==NULL || root->left==NULL || root->right==NULL){
        return;
    }

    else{
        convertTree(root->left);
        convertTree(root->right);

        if(root->left->data==1 && root->right->data==1){
            root->data=1;
        }
        else{
            root->data=0;
        }
    }
}

void printInorder(Node* node)  
{  
    if (node == NULL)  
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);  
}

int main(){
    Node *root=newNode(0); 
    root->left=newNode(1); 
    root->right=newNode(0); 
    root->left->left=newNode(0); 
    root->left->right=newNode(1); 
    root->right->left=newNode(1); 
    root->right->right=newNode(1); 
    printf("\n Inorder traversal before conversion "); 
    printInorder(root); 
    
    convertTree(root);

    printf("\n Inorder traversal After conversion "); 
    printInorder(root); 
    cout<<endl;
    return 0;
}