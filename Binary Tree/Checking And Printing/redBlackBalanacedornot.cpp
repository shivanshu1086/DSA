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

bool isBalancedUtil(node *root, int &maxh, int &minh){
    if(root==NULL){
        minh=maxh=0;
        return true;
    }

    int lmxh, lmnh;
    int rmxh, rmnh;

    if(isBalancedUtil(root->left,lmxh,lmnh)==false){
        return false;
    }

    if (isBalancedUtil(root->right, rmxh, rmnh) == false) 
        return false;

    maxh = max(lmxh, rmxh) + 1; 
    minh = min(lmnh, rmnh) + 1;

    if(maxh<=2*minh){
        return true;
    }

    return false;
}

bool isBalanced(node *root){
    int minh,maxh;
    return isBalancedUtil(root,maxh,minh);
}

int main(){
    node *root = newNode(10);
    root->left = newNode(5); 
    root->right = newNode(100); 
    root->right->left = newNode(50); 
    root->right->right = newNode(150); 
    root->right->left->left = newNode(40); 

    isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";
    cout<<endl;
    return 0;
}