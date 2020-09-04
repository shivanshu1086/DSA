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
// struct Node* insert(struct Node* node, int key) 
// { 
//     /* If the tree is empty, return a new node */
//     if (node == NULL) return newNode(key); 
  
//     /* Otherwise, recur down the tree */
//     if (key < node->data) 
//         node->left  = insert(node->left, key); 
//     else if (key > node->data) 
//         node->right = insert(node->right, key); 
  
//     /* return the (unchanged) node pointer */
//     return node; 
// }

void largestBSTBTUtil(Node *root, int *c){
    if(root==NULL || (root->left==NULL&&root->right==NULL)){
        return;
    }

    if(root->left!=NULL && root->right!=NULL){
        if(root->data>root->left->data && root->data<root->right->data)
            *c += 3;
    }
    else if(root->left==NULL && root->right!=NULL){
        if(root->data<root->right->data){
            *c += 2;
        }
    }
    else if(root->right==NULL && root->left!=NULL){
        if(root->data>root->left->data){
            *c+=2;
        }
    }
    largestBSTBTUtil(root->left,c);
    largestBSTBTUtil(root->right,c);
}

int largestBSTBT(Node *root){
    int coun=0;
    largestBSTBTUtil(root,&coun);
    return coun;
}

int main(){
    struct Node *root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(4); 
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    printf(" Size of the largest BST is %d\n", 
           largestBSTBT(root));
    cout<<endl;
    return 0;
}