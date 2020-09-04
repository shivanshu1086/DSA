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


Node* insert(Node* node, int data) 
{ 
    /* If the tree is empty,  
       return a new node */
    if (node == NULL) 
        return newNode(data); 
  
    /* Otherwise, recur down the tree */
    if (data <= node->data) 
        node->left = insert(node->left, data); 
    else
        node->right = insert(node->right, data); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

void inorder(Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
}

void modifyBSTUtil(Node* root, int* sum) 
{
    if(root==NULL){
        return;
    }

    modifyBSTUtil(root->right, sum);

    *sum = *sum + root->data;
    root->data = *sum;

    modifyBSTUtil(root->left,sum);
}

void modifyBST(Node* root) 
{ 
    int sum = 0; 
    modifyBSTUtil(root, &sum); 
}


int main(){
    Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);

    modifyBST(root);

    inorder(root);
    cout<<endl;
    return 0;
}