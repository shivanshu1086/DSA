#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* newNode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
}

void inorderTraversal(Node *root ){
    if(root==NULL){
        return;
    }
    else{
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

void Print(Node *root, int k1, int k2){
    if(root==NULL){
        return;
    }

    if ( k1 < root->data )Print(root->left,k1,k2);
    if(root->data>k1 && root->data<k2){
        printf("%d ",root->data);
    }
    if ( k2 > root->data )Print(root->right,k1,k2);
}


int main(){
    Node *root = new Node();
    int k1 = 10, k2 = 25;  
    
    root = newNode(20);  
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
      
    Print(root, k1, k2);
    cout<<endl;
    return 0;
}