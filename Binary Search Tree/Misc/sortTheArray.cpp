#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data){
    if(root==NULL){
        return newNode(data);
    }

    if(root->data>data){
        root->left =  insert(root->left,data);
    }
    else{
        root->right =  insert(root->right,data);
    }
    return root;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    int a[] = {4, 2, 5, 1, 3}; 
    int n = sizeof(a)/sizeof(int);
    Node *root = newNode(a[0]);
    for(int i=1;i<n;i++){
        insert(root,a[i]);
    }

    inorder(root);
    cout<<endl;
    return 0;
}