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
    temp->left = temp->right = NULL;
    return temp;
}

int parentSum(node *root, int x){
    static int ans=0;
    if(root==NULL || root->left==NULL || root->right==NULL){
        return 0;
    }

    if(root->left->data==x || root->right->data==x){
        ans+=root->data;
    }

    parentSum(root->left,x);
    parentSum(root->right,x);

    return ans;
}


int main(){
    node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(7);
    root->left->right = newNode(2);
    root->right->left = newNode(2); 
    root->right->right = newNode(3);

    int x=2;
    cout<<"Sum of parent node having child "<<x<<" : "<<parentSum(root,x);
    cout<<endl;
    return 0;
}