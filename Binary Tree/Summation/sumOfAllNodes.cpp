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

int addBT(node *root){
    if(root==NULL){
        return 0;
    }

    return (root->data + addBT(root->left) + addBT(root->right));
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8);

    int sum = addBT(root); 
    cout << "Sum of all the elements is: " << sum << endl;
    cout<<endl;
    return 0;
}