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

bool is_following_childreSum(node *root){
    if(root==NULL ||root->left==NULL || root->right==NULL){
        return true;
    }
    else{
        int left=0,right=0;
        is_following_childreSum(root->left);
        is_following_childreSum(root->right);

        if(root->left!=NULL){
            left=root->left->data;
        }

        if(root->right!=NULL){
            right = root->right->data;
        }

        if((left+right)!=root->data){
            return false;
        }
    }
    return true;
}

int main(){
    node *root = newNode(10);
    root->left = newNode(8);
    root->right =newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    is_following_childreSum(root) ? cout<<"Tree is following children sum property"<<endl : cout<<"Not following children sum property"<<endl;
    cout<<endl;
    return 0;
}