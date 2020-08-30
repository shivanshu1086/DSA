#include <iostream>

using namespace std;

class Node 
{ 
public: 
    int d; 
    Node* l, *r; 
    
};

Node* createNode(int d) 
{ 
    Node *node; 
    node = new Node; 
    node->d = d; 
    node->l = NULL; 
    node->r = NULL; 
    return node; 
}

int sumOfNodesAtMaxDepth(Node *root, int &ans){
    if(root==NULL){
        return 0;
    }

    sumOfNodesAtMaxDepth(root->l,ans);
    sumOfNodesAtMaxDepth(root->r,ans);
    if(root->l==NULL && root->r==NULL){
        ans+=root->d;
    }
    return ans;
}

int main(){
    Node *root; 
    root = createNode(1); 
    root->l = createNode(2); 
    root->r = createNode(3); 
    root->l->l = createNode(4); 
    root->l->r = createNode(5); 
    root->r->l = createNode(6); 
    root->r->r = createNode(7);
    int sum=0;
    sumOfNodesAtMaxDepth(root, sum); 
    cout << sum; 
    cout<<endl;
    return 0;
}