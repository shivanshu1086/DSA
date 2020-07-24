#include <iostream>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data = x;
    tmp->left=tmp->right=NULL;
    return tmp;
}
vector<int> in;
vector<int> pre;
vector<int> post;

void inOrder(node *root){
    if(root==NULL){
        return;
    }
    else{
        inOrder(root->left);
        in.push_back(root->data);
        inOrder(root->right);
    }
}

void preOrder(node *root){
    if(root==NULL){
        return;
    }
    else{
        pre.push_back(root->data);
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
        post.push_back(root->data);
    }
}

int main(){
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);
    inOrder(root);
    preOrder(root);
    postOrder(root);
    cout<<in[4]<<" "<<pre[4]<<" "<<post[4];
	cout<<endl;
    return 0;
}
