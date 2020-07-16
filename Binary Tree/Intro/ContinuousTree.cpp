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

bool treeContinuous(node *root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }

    if(root->left==NULL){
        return (abs(root->data-root->right->data)==1)&&treeContinuous(root->right);
    }
    if(root->right==NULL){
        return (abs(root->data-root->left->data)==1)&&treeContinuous(root->left);
    }

    return (abs(root->data-root->left->data)==1)
            &&(abs(root->data-root->right->data)==1)
            &&treeContinuous(root->left)
            &&treeContinuous(root->right);
}

int main(){
    node *root        = newNode(3);
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5);
    treeContinuous(root)?  cout << "Yes" : cout << "No";
	cout<<endl;
    return 0;
}
