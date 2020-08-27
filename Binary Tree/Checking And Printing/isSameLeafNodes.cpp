#include <iostream>
#include <vector>
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

bool isLeaf(node* root) 
{ 
    if(root == NULL) 
        return false; 
    if(!root->left && !root->right) 
        return true; 
    return false; 
}

void firstTreeNodes(node *root, vector<int> &v1){
    if(root==NULL){
        return;
    }

    else{
        firstTreeNodes(root->left,v1);
        if(isLeaf(root)){
            v1.push_back(root->data);
        }
        firstTreeNodes(root->right,v1);
    }
}

void secondTreeNodes(node *root, vector<int> &v2){
    if(root==NULL){
        return;
    }

    else{
        secondTreeNodes(root->left,v2);
        if(isLeaf(root)){
            v2.push_back(root->data);
        }
        secondTreeNodes(root->right,v2);
    }
}

bool isSameLeafNodes(node *root1, node *root2){
    vector<int> v1,v2;

    firstTreeNodes(root1, v1);
    secondTreeNodes(root2, v2);

    return v1==v2;
}

int main(){
    node *root1 = newNode(1);
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->right->left = newNode(6); 
    root1->right->right = newNode(7);

    node *root2 = newNode(0);
    root2->left = newNode(1); 
    root2->right = newNode(5); 
    root2->left->right = newNode(4); 
    root2->right->left = newNode(6); 
    root2->right->right = newNode(7);

    if(isSameLeafNodes(root1, root2)) 
        cout << "Same"; 
    else
        cout << "Not Same";
    
    cout<<endl;
    return 0;
}