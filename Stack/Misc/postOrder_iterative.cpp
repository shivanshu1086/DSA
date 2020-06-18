#include <iostream>
#include <stack>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data){
    node *n=new node();
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

void postOrder(node *root){
    
    if(root==NULL){
        return;
    }

    stack<node *> s1,s2;

    s1.push(root);
    node *Node;
    while(!s1.empty()){
        Node = s1.top();
        s1.pop();
        s2.push(Node);

        if(Node->left){
            s1.push(Node->left);
        }
        if(Node->right){
            s1.push(Node->right);
        }
    }

    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main(){
    node *root = NULL;
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);
    postOrder(root);
    cout<<endl;
	return 0; 
}