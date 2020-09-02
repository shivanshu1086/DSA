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

void printPreorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    cout << root->data << " "; 
    printPreorder(root->left);
    printPreorder(root->right); 
}

Node *LevelOrder(Node *root, int data){
    if(root==NULL){     
        root = newNode(data); 
        return root; 
    }

    if(data<=root->data){
        root->left = LevelOrder(root->left, data);
    }
    else{
        root->right = LevelOrder(root->right, data);
    }
    return root;
}

Node *constructBst(int *arr, int n){
    if(n==0){
        return NULL;
    }

    Node *root =NULL;

    for(int i=0;i<n;i++) 
    root = LevelOrder(root , arr[i]);

    return root;
}

int main(){
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = constructBst(arr, n);
    cout << "Inorder Traversal: ";
    printPreorder(root);
    cout<<endl;
    return 0;
}