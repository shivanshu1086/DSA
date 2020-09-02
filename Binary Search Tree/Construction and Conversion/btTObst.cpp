#include <iostream>
#include <algorithm>

using namespace std;

class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
};  
  
// A utility function to create a node  
node* newNode (int data)  
{  
    node* temp = new node(); 
  
    temp->data = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}

void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    printf("%d ", node->data); 
  
    /* now recur on right child */
    printInorder(node->right); 
}

int countNodes(node *root){
    if(root==NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void storeInorder(node *root, int arr[], int *i){
    if(root==NULL){
        return;
    }

    else{
        storeInorder(root->left,arr,i);
        arr[(*i)++]=root->data;
        storeInorder(root->right,arr,i);
    }
}

void arrayToBST(int *arr, node *root, int *i){
    if(root==NULL){
        return;
    }

    arrayToBST(arr,root->left,i);
    root->data = arr[(*i)++];
    arrayToBST(arr,root->right,i);
}

void binaryTreeToBST(struct node* root) 
{
    if (root == NULL) 
        return;

    int n = countNodes(root);//for array size

    int* arr = new int[n]; 
    int i = 0;

    storeInorder(root, arr, &i);

    sort(arr,arr+n);

    i = 0; 
    arrayToBST(arr, root, &i);

    delete []arr;
}

int main(){
    struct node* root = NULL;
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5);

    binaryTreeToBST(root);

    printf("Following is Inorder Traversal of the converted BST: \n"); 
    printInorder(root);
    cout<<endl;
    return 0;
}