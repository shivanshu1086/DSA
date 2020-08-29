#include <iostream>
#include <unordered_set>
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

int isSymmetric(node *root1, node *root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1==NULL || root2==NULL){
        return false;
    }

    return (root1->data==root2->data) && (isSymmetric(root1->left,root2->right)) && (isSymmetric(root1->right,root2->left));
}


int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(4); 
    root->right->right = newNode(3);

    if(isSymmetric(root->left,root->right)) 
        cout << "The given tree is Symmetric"; 
    else
        cout << "The given tree is not Symmetric";
    cout<<endl;
    return 0;
}