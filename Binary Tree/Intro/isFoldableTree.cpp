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

bool isFoldableUtil(node *l1, node *l2){
    if(l1==NULL && l2==NULL){
        return true;
    }

    if(l1==NULL || l2==NULL){
        return false;
    }

    return isFoldableUtil(l1->left, l2->right) && isFoldableUtil(l1->right,l2->left);
}

bool isFoldable(node *root){
    if(root==NULL){
        return true;
    }
    else{
        return isFoldableUtil(root->left,root->right);
    }
}


int main(){
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5);
    isFoldable(root)? cout<<"Yes":cout<<"NO";
	cout<<endl;
    return 0;
}
