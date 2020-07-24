#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dd=1;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int x){
        data = x;
        left=NULL;
        right=NULL;
    }
};

node *newNode(int x){
    node *tmp = new node(x);
    return tmp;
}

void inOrder(node *root){
    if(root==NULL){
        return;
    }
    else{
        inOrder(root->left);
        v.push_back(root->data);
        inOrder(root->right);
    }
}

void replace(node *root){
    if(root==NULL){
        return;
    }
    else{
        replace(root->left);
        root->data = v[dd+1]+v[dd-1];
        dd++;
        replace(root->right);
    }
}

void preorderTraversal(node* root){
    if (!root) 
        return; 

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right); 
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    preorderTraversal(root);
    cout<<endl;
    v.push_back(0);
    inOrder(root);
    v.push_back(0);
    replace(root);
    preorderTraversal(root);
	cout<<endl;
    return 0;
}
