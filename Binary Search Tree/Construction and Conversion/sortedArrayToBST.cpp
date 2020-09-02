#include <iostream>

using namespace std;

class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
};  

node * newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return Node;  
}  


void preOrder(node* node)  
{  
    if (node == NULL)  
        return;  
    cout << node->data << " ";  
    preOrder(node->left);  
    preOrder(node->right);  
}  

node *sortedArrayToBST(int arr[], int low, int high){
    if (low > high)  
    return NULL;

    int mid = (low+high)/2;

    node *root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr,low,mid-1);

    root->right = sortedArrayToBST(arr,mid+1,high);

    return root;
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]); 

    node *root = sortedArrayToBST(arr, 0, n-1);  
    cout << "PreOrder Traversal of constructed BST \n";  
    preOrder(root);

    cout<<endl;
    return 0;
}