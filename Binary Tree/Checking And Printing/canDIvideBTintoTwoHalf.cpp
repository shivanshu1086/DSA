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

int count(node *root){
    if (root==NULL) 
        return 0; 
    return count(root->left) + count(root->right) + 1;
}

bool checkRec(node *root, int n){
    if(root==NULL){
        return false;
    }

    if(count(root)==n-count(root)){
        return true;
    }

    return checkRec(root->left, n) || 
           checkRec(root->right, n);
}

bool check(node *root){
    int n = count(root);
    return checkRec(root, n);
}

int main(){
    node *root = newNode(5);
    root->left = newNode(1); 
    root->right = newNode(6); 
    root->left->left = newNode(3); 
    root->right->left = newNode(7); 
    root->right->right = newNode(4);

    check(root)?  printf("YES") : printf("NO");
    cout<<endl;
    return 0;
}