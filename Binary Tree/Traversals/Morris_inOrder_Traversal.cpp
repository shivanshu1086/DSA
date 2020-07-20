#include <iostream>
#include <stack>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *tmp = new node();
    tmp->data = x;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void Morris_inOrder_Traversal(node *root){
    if(root==NULL){
        return;
    }
    node *current, *prev;
    current = root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            prev = current->left;
            while(prev->right!=NULL && prev->right!=current){
                prev = prev->right;
            }
            if(prev->right==NULL){
                prev->right = current;
                current = current->left;
            }
            else{
                prev->right=NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}

int main(){
    node *root = newNode(1);
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5);
    Morris_inOrder_Traversal(root);
	cout<<endl;
    return 0;
}
