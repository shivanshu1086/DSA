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

int level(node *root, node *node1, int lvl){
    if(root==NULL){
        return 0;
    }
    if(root==node1){
        return lvl;
    }

    int l = level(root->left,node1,lvl+1);

    if(l!=0){
        return l;
    }

    return level(root->right,node1,lvl+1);
}

bool same_parents(node *root, node *a, node *b){
    if(root==NULL){
        return false;
    }

    return ((root->left==a && root->right==b) || (root->left==b && root->right==a) || same_parents(root->left,a,b) || same_parents(root->right,a,b));
}

int are_cousins(node *root, node *node1, node *node2){
    if((level(root,node1,1)==level(root,node2,1)) && (same_parents(root,node1,node2)==false)){
        return 1;
    }
    return 0;
}

int main(){
    node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8);

    node *node1, *node2;
    node1 = root->left->left;
    node2 = root->right->right;

    are_cousins(root,node1,node2)?cout<<"Yes they are cousins":cout<<"They are not cousins";
    cout<<endl;
    return 0;
}