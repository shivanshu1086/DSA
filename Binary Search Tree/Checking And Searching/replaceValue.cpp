#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
};

struct Node* newnode(int item) 
{ 
    struct Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void insert(Node *&root, int x, Node *&succ){
    if(root==NULL){
        root =  newnode(x);
    }
    if(root->data>x){
        succ = root;
        insert(root->left,x,succ);
    }
    else if(root->data<x){
        insert(root->right,x,succ);
    }
}

void replace(int arr[], int n) 
{ 
    Node* root = NULL;
    for (int i = n - 1; i >= 0; i--) 
    { 
        Node* succ = NULL;
        insert(root, arr[i], succ);

        if (succ) 
            arr[i] = succ->data;

        else    // No inorder successor 
            arr[i] = -1;
    }
}

int main(){
    int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 
                  43, 3, 91, 93, 25, 80, 28 }; 
    int n = sizeof(arr)/ sizeof(arr[0]); 
  
    replace(arr, n); 
  
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout<<endl;
    return 0;
}