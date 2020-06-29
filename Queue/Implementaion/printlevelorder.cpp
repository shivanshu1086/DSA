#include <iostream>
#include <queue>
#include <list>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int x){
    node *Node = new node();
    Node->data=x;
    Node->right=NULL;
    Node->left=NULL;
    return Node;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight){
            return lheight+1;
        }
        else{
            return rheight+1;
        }
    }
}

void printGivenLevel(node *root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level>1){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void printlevelorder(node *root){
    int h = height(root);
    for(int i=1;i<=h;i++){
        printGivenLevel(root,i);
    }
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printlevelorder(root);
    cout<<endl;
	return 0;
}