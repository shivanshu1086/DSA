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

bool isMirror(node *root1, node *root2){
    if(!root1 && !root2){
        return true;
    }

    if(root1 && root2 && root1->data==root2->data){
        return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    }

    return false;
}

bool isSymmetric(node *root){
    return isMirror(root,root);
}

int main(){
    node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3);
    cout << isSymmetric(root);
	cout<<endl;
    return 0;
}
