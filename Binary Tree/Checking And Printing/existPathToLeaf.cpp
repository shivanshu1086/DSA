#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newnode(int x){
    node *temp = new node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

bool existPathUtil(node *root, int arr[], int n, int index){
    if(root == NULL or index==n)  
        return false;
    
    if (root->left == NULL && root->right == NULL) 
    { 
        if((root->data == arr[index]) && (index == n-1))  
            return true;  
         
       return false; 
    }


    return ((index < n) && (root->data == arr[index]) && 
                (existPathUtil(root->left, arr, n, index+1) || 
                existPathUtil(root->right, arr, n, index+1) ));
}

bool existPath(node *root, int arr[], int n, int index) 
{ 
    if(!root) 
        return (n==0); 
          
    return existPathUtil(root, arr, n, 0);
}

int main(){
    int arr[] = {5, 8, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    node *root = newnode(5);
    root->left = newnode(3); 
    root->right = newnode(8); 
    root->left->left = newnode(2); 
    root->left->right = newnode(4); 
    root->left->left->left = newnode(1); 
    root->right->left = newnode(6); 
    root->right->left->right = newnode(7);
    
    existPath(root, arr, n, 0)? cout << "Path Exists" : 
                                cout << "Path does not Exist";
    cout<<endl;
    return 0;
}