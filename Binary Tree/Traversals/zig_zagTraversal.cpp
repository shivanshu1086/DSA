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
    tmp->data=x;
    tmp->left=tmp->right=NULL;
    return tmp;
}

void printSpiral(node *root){
    if(root==NULL){
        return;
    }
    stack<node *> s1;
    stack<node *> s2;

    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node *temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left);
        }
        while(!s2.empty()){
            node * temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right);
        }
    }
}

int main(){
    node *root= newNode(1);
    root->left =  newNode(2);
    root->right =  newNode(3);
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n"; 
    printSpiral(root);
	cout<<endl;
    return 0;
}
