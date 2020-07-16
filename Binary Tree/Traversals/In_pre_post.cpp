#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp=new node();
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void inOrder(node *root){
    if(root==NULL){
        return;
    }
    else{
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void preOrder(node *root){
    if(root==NULL){
        return;
    }

    else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root){
    if(root==NULL){
        return;
    }
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
	cout<<endl;
    return 0;
}
