#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *temp=new node();
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

int is_leaf(node *node){
    if(node==NULL){
        return 0;
    }
    if(node->left==NULL && node->right==NULL){
        return 1;
    }
    return 0;
}

bool isSumTree(node *root){
    if(root==NULL || is_leaf(root)){
        return true;
    }

    else{
        int left=0,right=0;
        isSumTree(root->left);
        isSumTree(root->right);
        if(root->left==NULL){
            left=0;
        }
        else if(is_leaf(root->left)){
            left=root->left->data;
        }
        else{
            left=2*root->left->data;
        }

        if(root->right==NULL){
            right=0;
        }
        else if(is_leaf(root->right)){
            right=root->right->data;
        }
        else{
            right=2*root->right->data;
        }

        if((left+right)!=root->data){
            return false;
        }
    }
    return true;
}

int main(){
    node *root = newNode(28);
    root->left = newNode(11);
    root->right =newNode(3);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root)) 
        printf("The given tree is a SumTree "); 
    else
        printf("The given tree is not a SumTree ");
    cout<<endl;
    return 0;
}