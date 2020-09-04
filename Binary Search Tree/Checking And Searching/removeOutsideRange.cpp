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


Node *removeOutsideRange(Node *root, int min, int max){
    if(root==NULL){
        return NULL;
    }

    root->left =  removeOutsideRange(root->left, min, max); 
    root->right =  removeOutsideRange(root->right, min, max);

    if(root->data<min){
        Node *rChild = root->right;
        delete root;
        return rChild;
    }

    if(root->data>max){
        Node *lChild = root->left;
        delete root;
        return lChild;
    }

    return root;
}

int main(){
    Node* root = NULL; 
    root = insert(root, 6); 
    root = insert(root, -13); 
    root = insert(root, 14); 
    root = insert(root, -8); 
    root = insert(root, 15); 
    root = insert(root, 13); 
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: "; 
    inorderTraversal(root); 
  
    root = removeOutsideRange(root, -10, 13); 
  
    cout << "\nInorder traversal of the modified tree is: "; 
    inorderTraversal(root);

    cout<<endl;
    return 0;
}