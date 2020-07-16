#include <iostream>

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

int main(){
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    
	cout<<endl;
    return 0;
}
