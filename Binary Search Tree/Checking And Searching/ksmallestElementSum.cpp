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

struct Node* insert(struct Node* root, int data) 
{ 
    if (root == NULL) 
        return newNode(data); 
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else if (data > root->data) 
        root->right = insert(root->right, data); 
    return root; 
}

void ksmallestElementSumUtil(Node *root, int *k, int *sum){
    if(root){
        ksmallestElementSumUtil(root->left,k,sum);
        if(*k==0){
            return;
        }
        else if(*k>=0){
            *k = *k-1;
            *sum = *sum+root->data;
        }
        ksmallestElementSumUtil(root->right,k,sum);
    }
}

int ksmallestElementSum(Node *root, int k){
    int sum = 0;
    ksmallestElementSumUtil(root,&k,&sum);
    return sum;
}


int main(){
    Node *root = NULL; 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14); 
    root = insert(root, 22); 
  
    int k = 5; 
    cout <<  ksmallestElementSum(root, k) <<endl; 
    cout<<endl;
    return 0;
}