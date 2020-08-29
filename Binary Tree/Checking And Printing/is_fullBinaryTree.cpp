#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp = new node();
    temp->data = x;
    temp->left=temp->right=NULL;
    return temp;
}

bool is_fullBinaryTree(node *root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return true;
    }

    else{
        if(root->left && root->right){
            return (is_fullBinaryTree(root->left) && is_fullBinaryTree(root->right));
        }
    }
    return false;
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    // root->left->right = newNode(5);

    if(is_fullBinaryTree(root)){
        cout<<"The tree is full Binary Tree"<<endl;
    }
    else{
        cout<<"Not a binary Tree"<<endl;
    }
    cout<<endl;
    return 0;
}